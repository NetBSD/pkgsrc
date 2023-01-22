# $NetBSD: cwrappers.mk,v 1.39 2023/01/22 23:36:24 rillig Exp $
#
# This Makefile fragment implements integration of pkgtools/cwrappers.

.include "../../mk/wrapper/wrapper-defs.mk"
.include "../../mk/buildlink3/bsd.buildlink3.mk"

TOOL_DEPENDS+=		cwrappers>=20150314:../../pkgtools/cwrappers

# XXX This should be PREFIX, but USE_CROSSBASE overrides it.
CWRAPPERS_SRC_DIR=	${LOCALBASE}/libexec/cwrappers
CWRAPPERS_CONFIG_DIR=	${WRKDIR}/.cwrapper/config
CONFIGURE_ENV+=		CWRAPPERS_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR}
MAKE_ENV+=		CWRAPPERS_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR}
ALL_ENV+=		CWRAPPERS_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR}

# TODO: Fix direct calls to CC and LIBTOOL to provide correct environment.
.export CWRAPPERS_CONFIG_DIR

CWRAPPERS_CONFIG.as=		as
CWRAPPERS_CONFIG.cc=		cc
CWRAPPERS_CONFIG.cxx=		c++
CWRAPPERS_CONFIG.cpp=		cpp
CWRAPPERS_CONFIG.f77=		f77
CWRAPPERS_CONFIG.imake=		imake
CWRAPPERS_CONFIG.ld=		ld
CWRAPPERS_CONFIG.libtool=	libtool
CWRAPPERS_CONFIG.shlibtool=	shlibtool

CWRAPPERS_ALIASES.as=		as
CWRAPPERS_ALIASES.cc=		cc gcc clang
CWRAPPERS_ALIASES.cxx=		c++ g++ cxx clang++
CWRAPPERS_ALIASES.cpp=		cpp clang-cpp
CWRAPPERS_ALIASES.f77=		f77 g77 gfortran
CWRAPPERS_ALIASES.imake=	imake
CWRAPPERS_ALIASES.ld=		ld
CWRAPPERS_ALIASES.libtool=	libtool
CWRAPPERS_ALIASES.shlibtool=	shlibtool

.if !empty(TOOLS_USE_CROSS_COMPILE:M[yY][eE][sS])
CWRAPPERS_ALIASES.cc+=		${CC:T}
CWRAPPERS_ALIASES.cxx+=		${CXX:T}
CWRAPPERS_ALIASES.ld+=		${LD:T}
.endif

CWRAPPERS_WRAPPEE.as=		${AS:Ufalse}
CWRAPPERS_WRAPPEE.cxx=		${PKG_CXX:Ufalse}
CWRAPPERS_WRAPPEE.cc=		${PKG_CC:Ufalse}
CWRAPPERS_WRAPPEE.cpp=		${PKG_CPP:Ufalse}
CWRAPPERS_WRAPPEE.f77=		${PKG_FC:Ufalse}
CWRAPPERS_WRAPPEE.imake=	${TOOLS_PATH.imake:Ufalse}
CWRAPPERS_WRAPPEE.ld=		${LD:Ufalse}
CWRAPPERS_WRAPPEE.libtool=	${PKG_LIBTOOL:Ufalse}
CWRAPPERS_WRAPPEE.shlibtool=	${PKG_SHLIBTOOL:Ufalse}

# TODO: Find and fix packages depending on the implicit include path.
CWRAPPERS_APPEND.cc+=		-I${PREFIX}/include
CWRAPPERS_APPEND.cxx+=		-I${PREFIX}/include
CWRAPPERS_APPEND.cpp+=		-I${PREFIX}/include

.if defined(USE_IMAKE) || !empty(USE_TOOLS:Mimake)
CWRAPPERS_TRANSFORM.imake+=	I:${PREFIX}/lib/X11/config:${PREFIX}/lib/X11/config
CWRAPPERS_APPEND.imake+=	${IMAKEOPTS}
.endif

.PHONY: generate-cwrappers

.for _target_ in ${WRAPPER_TARGETS}
generate-cwrappers: ${_target_}
.endfor

generate-cwrappers:
.for wrappee in as cxx cc cpp f77 imake ld libtool shlibtool
	${RUN} { \
		echo worklog=${WRKLOG:Q}; \
		echo wrksrc=${WRKSRC:Q}; \
		case ${wrappee} in \
		*libtool) ;; \
		*) echo path=${_PATH_COMPONENTS:N${WRAPPER_BINDIR}:ts::Q}; \
		esac; \
		echo exec_path=${WRAPPER_BINDIR}/${CWRAPPERS_ALIASES.${wrappee}:[1]}; \
		echo exec=${CWRAPPERS_WRAPPEE.${wrappee}:Q}; \
		${WRAPPER_REORDER_CMDS:@cmd@ \
			echo reorder=${cmd:S/^reorder://:Q}; \
		@} \
		${CWRAPPERS_TRANSFORM.${wrappee}:@cmd@ \
			echo transform=${cmd:Q}; \
		@} \
		${_CWRAPPERS_TRANSFORM:@cmd@ \
			echo transform=${cmd:Q}; \
		@} \
		${CWRAPPERS_APPEND.${wrappee}:U:@cmd@ \
			echo append=${cmd:Q}; \
		@} \
		${CWRAPPERS_PREPEND.${wrappee}:U:@cmd@ \
			echo prepend=${cmd:Q}; \
		@} \
		${_CWRAPPERS_UNWRAP:@cmd@ \
			echo unwrap=${cmd:Q}; \
		@} \
	} > ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
.  for alias in ${CWRAPPERS_ALIASES.${wrappee}}
	${RUN}ln -s ${CWRAPPERS_SRC_DIR}/${CWRAPPERS_CONFIG.${wrappee}}-wrapper ${WRAPPER_BINDIR}/${alias}
.  endfor
. if ${_PKGSRC_MKPIE} == "yes"
.  if ${PKGSRC_OVERRIDE_MKPIE:tl} == "no"
.    for arg in ${_MKPIE_LDFLAGS}
	${RUN}echo append_executable=${arg} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
.    endfor
.  endif
. endif
.endfor

PREPEND_PATH+=		${WRAPPER_BINDIR}

_COOKIE.wrapper=	${WRKDIR}/.wrapper_done

.PHONY: wrapper
.if !target(wrapper)
.  if exists(${_COOKIE.wrapper}) && !${_CLEANING}
wrapper:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
wrapper: check-vulnerable patch acquire-wrapper-lock ${_COOKIE.wrapper} release-wrapper-lock
.  else
wrapper: barrier
.  endif
.endif

.PHONY: acquire-wrapper-lock release-wrapper-lock
acquire-wrapper-lock: acquire-lock
release-wrapper-lock: release-lock

.if exists(${_COOKIE.wrapper}) && !${_CLEANING}
${_COOKIE.wrapper}:
	@${DO_NADA}
.else
${_COOKIE.wrapper}: real-wrapper
.endif

.PHONY: real-wrapper
real-wrapper: wrapper-message wrapper-dirs wrapper-vars pre-wrapper do-wrapper post-wrapper wrapper-cookie error-check

.PHONY: wrapper-message
wrapper-message:
	@${PHASE_MSG} "Creating toolchain wrappers for ${PKGNAME}"

.PHONY: wrapper-dirs
wrapper-dirs:
	@${MKDIR} ${CWRAPPERS_CONFIG_DIR} ${WRAPPER_BINDIR}

.PHONY: pre-wrapper do-wrapper post-wrapper

do-wrapper: generate-cwrappers

.if !target(do-wrapper)
do-wrapper:
	@${DO_NADA}
.endif

.if !target(pre-wrapper)
pre-wrapper:
	@${DO_NADA}
.endif

.if !target(post-wrapper)
post-wrapper:
	@${DO_NADA}
.endif

.PHONY: wrapper-cookie
wrapper-cookie:
	${RUN}								\
	[ ! -f ${_COOKIE.wrapper} ];					\
	${TEST} -d ${_COOKIE.wrapper:H} || ${MKDIR} ${_COOKIE.wrapper:H}; \
	${ECHO} ${PKGNAME} > ${_COOKIE.wrapper}
