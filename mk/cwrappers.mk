# $NetBSD: cwrappers.mk,v 1.19 2014/12/12 10:12:50 joerg Exp $
#
# This Makefile fragment implements integration of pkgtools/cwrappers.

BUILD_DEPENDS+=		cwrappers>=20141129:../../pkgtools/cwrappers

# XXX This should be PREFIX, but USE_CROSSBASE overrides it.
CWRAPPERS_SRC_DIR=	${LOCALBASE}/libexec/cwrappers
CWRAPPERS_BIN_DIR=	${WRKDIR}/.cwrapper/bin
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
CWRAPPERS_ALIASES.f77=		f77 g77
CWRAPPERS_ALIASES.imake=	imake
CWRAPPERS_ALIASES.ld=		ld
CWRAPPERS_ALIASES.libtool=	libtool
CWRAPPERS_ALIASES.shlibtool=	shlibtool

CWRAPPERS_WRAPPEE.as=		${AS:Ufalse}
CWRAPPERS_WRAPPEE.cxx=		${PKG_CXX:Ufalse}
CWRAPPERS_WRAPPEE.cc=		${PKG_CC:Ufalse}
CWRAPPERS_WRAPPEE.cpp=		${PKG_CPP:Ufalse}
CWRAPPERS_WRAPPEE.f77=		${PKG_FC:Ufalse}
CWRAPPERS_WRAPPEE.imake=	${IMAKE:Ufalse}
CWRAPPERS_WRAPPEE.ld=		${LD:Ufalse}
CWRAPPERS_WRAPPEE.libtool=	${PKG_LIBTOOL:Ufalse}
CWRAPPERS_WRAPPEE.shlibtool=	${PKG_SHLIBTOOL:Ufalse}

# TODO: Find and fix packages depending on the implicit include path.
CWRAPPERS_APPEND.cc+=		-I${PREFIX}/include
CWRAPPERS_APPEND.cxx+=		-I${PREFIX}/include
CWRAPPERS_APPEND.cpp+=		-I${PREFIX}/include

.if defined(USE_IMAKE) || !empty(USE_TOOLS:Mimake)
CWRAPPERS_TRANSFORM.imake+=	I:${PREFIX}/lib/X11/config:${PREFIX}/lib/X11/config
.endif

.PHONY: generate-cwrappers

do-wrapper: generate-cwrappers

generate-cwrappers:
	${RUN}${MKDIR} ${CWRAPPERS_CONFIG_DIR} ${CWRAPPERS_BIN_DIR}
.for wrappee in as cxx cc cpp f77 imake ld libtool shlibtool
	${RUN}echo worklog=${WRKLOG:Q} > ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
	${RUN}echo wrksrc=${WRKSRC:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
	${RUN}case ${wrappee} in *libtool) ;; *) echo path=${_PATH_ORIG:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}};; esac
	${RUN}echo exec_path=${CWRAPPERS_BIN_DIR}/${CWRAPPERS_ALIASES.${wrappee}:[1]} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
	${RUN}echo exec=${CWRAPPERS_WRAPPEE.${wrappee}:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
.  for cmd in ${WRAPPER_REORDER_CMDS}
	${RUN}echo reorder=${cmd:S/^reorder://:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
.  endfor
.  for cmd in ${CWRAPPERS_TRANSFORM.${wrappee}} ${_CWRAPPERS_TRANSFORM}
	${RUN}echo transform=${cmd:u:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
.  endfor
.  for cmd in ${CWRAPPERS_APPEND.${wrappee}:U}
	${RUN}echo append=${cmd:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
.  endfor
.  for cmd in ${_CWRAPPERS_UNWRAP}
	${RUN}echo unwrap=${cmd:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
.  endfor
.  for alias in ${CWRAPPERS_ALIASES.${wrappee}}
	${RUN}ln -s ${CWRAPPERS_SRC_DIR}/${CWRAPPERS_CONFIG.${wrappee}}-wrapper ${CWRAPPERS_BIN_DIR}/${alias}
.  endfor
.endfor

.if defined(USE_LIBTOOL)
_LIBTOOL=		${CWRAPPERS_BIN_DIR}/libtool
_SHLIBTOOL=		${CWRAPPERS_BIN_DIR}/shlibtool
.endif
PREPEND_PATH+=		${CWRAPPERS_BIN_DIR}
