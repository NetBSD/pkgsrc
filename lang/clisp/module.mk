# $NetBSD: module.mk,v 1.12 2019/11/02 10:20:42 rillig Exp $
#
# Package-settable variables:
#
# CLISP_MODULE
#	name of module and subdirectory in "modules"

CLISP_VERSION=		2.49
DISTNAME=		clisp-${CLISP_VERSION}

CONFIGURE_DIRS=		modules/${CLISP_MODULE}
GNU_CONFIGURE=		YES
BUILD_TARGET=		clisp-module	# converting to "all"

CONFIGURE_ENV+=		ac_install_sh="install -c"
CONFIGURE_ENV+=		ac_aux_dir=${PREFIX}/lib/clisp/build-aux/
#TEST_TARGET=		check mod-check

INSTALLATION_DIRS=	lib/clisp

.if !target(do-install)
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/clisp/dynmod
	cd ${WRKSRC}/modules;	\
	${SETENV} ${MAKE_ENV} ${INSTALL_ENV} sh ${PREFIX}/bin/clisp-link install ${CLISP_MODULE}
.endif

.include "../../lang/clisp/buildlink3.mk"
