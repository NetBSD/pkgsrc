# $NetBSD: cwrappers.mk,v 1.1 2014/11/24 00:32:31 joerg Exp $
#
# This Makefile fragment implements integration of pkgtools/cwrappers.

BUILD_DEPENDS+=		cwrappers>=20100308:../../pkgtools/cwrappers

CWRAPPERS_SRC_DIR=	${PREFIX}/libexec/cwrappers
CWRAPPERS_BIN_DIR=	${WRKDIR}/.cwrapper/bin
CWRAPPERS_CONFIG_DIR=	${WRKDIR}/.cwrapper/config
CONFIGURE_ENV+=		WRAPPER_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR}
MAKE_ENV+=		WRAPPER_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR}
ALL_ENV+=		WRAPPER_CONFIG_DIR=${CWRAPPERS_CONFIG_DIR}

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
CWRAPPERS_ALIASES.cc=		cc gcc
CWRAPPERS_ALIASES.cxx=		c++ g++ CC cxx
CWRAPPERS_ALIASES.cpp=		cpp
CWRAPPERS_ALIASES.f77=		f77 g77
CWRAPPERS_ALIASES.imake=		imake
CWRAPPERS_ALIASES.ld=		ld
CWRAPPERS_ALIASES.libtool=	libtool
CWRAPPERS_ALIASES.shlibtool=	shlibtool

CWRAPPERS_WRAPPEE.as=	${AS:Ufalse}
CWRAPPERS_WRAPPEE.cxx=	${CXX:Ufalse}
CWRAPPERS_WRAPPEE.cc=	${CC:Ufalse}
CWRAPPERS_WRAPPEE.cpp=	${CPP:Ufalse}
CWRAPPERS_WRAPPEE.f77=	${F77:Ufalse}
CWRAPPERS_WRAPPEE.imake=	${IMAKE:Ufalse}
CWRAPPERS_WRAPPEE.ld=	${LD:Ufalse}
CWRAPPERS_WRAPPEE.libtool=	${PREFIX}/bin/libtool
CWRAPPERS_WRAPPEE.shlibtool=	${PREFIX}/bin/shlibtool

.PHONY: generate-cwrapper

do-wrapper: generate-cwrapper

generate-cwrapper:
	${RUN}${MKDIR} ${CWRAPPERS_CONFIG_DIR} ${CWRAPPERS_BIN_DIR}
.for wrappee in as cxx cc cpp f77 imake ld libtool shlibtool
	${RUN}echo worklog=${WRKLOG:Q} > ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
	${RUN}echo wrksrc=${WRKSRC:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
	${RUN}case ${wrappee} in *libtool) ;; *) echo path=${_PATH_ORIG:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}};; esac
	${RUN}echo exec=${CWRAPPERS_WRAPPEE.${wrappee}:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
.  for cmd in ${WRAPPER_REORDER_CMDS
	${RUN}echo reorder=${cmd:S/^reorder://:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
.  endfor
.  for cmd in ${_CWRAPPERS_TRANSFORM}
	${RUN}echo transform=${cmd:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
.  endfor
.  for cmd in ${_CWRAPPERS_UNWRAP}
	${RUN}echo unwrap=${cmd:Q} >> ${CWRAPPERS_CONFIG_DIR}/${CWRAPPERS_CONFIG.${wrappee}}
.  endfor
.  for alias in ${CWRAPPERS_ALIASES.${wrappee}}
	${RUN}ln -s ${CWRAPPERS_SRC_DIR}/${CWRAPPERS_CONFIG.${wrappee}}-wrapper ${CWRAPPERS_BIN_DIR}/${alias}
.  endfor
.endfor

_LIBTOOL=		${CWRAPPERS_BIN_DIR}/libtool
_SHLIBTOOL=		${CWRAPPERS_BIN_DIR}/shlibtool
PREPEND_PATH+=		${CWRAPPERS_BIN_DIR}
