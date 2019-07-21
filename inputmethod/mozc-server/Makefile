# $NetBSD: Makefile,v 1.50 2019/07/21 22:25:11 wiz Exp $

PKGNAME=	${DISTNAME:S/mozc-/mozc-server-/}
PKGREVISION=	16

INSTALLATION_DIRS+=	libexec

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build \
		-c ${MOZC_BUILD_MODE} \
			server/server.gyp:mozc_server

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/${MOZC_BUILD_MODE}/mozc_server \
		${DESTDIR}${PREFIX}/libexec/mozc_server

.include "../../inputmethod/mozc-server/Makefile.common"
