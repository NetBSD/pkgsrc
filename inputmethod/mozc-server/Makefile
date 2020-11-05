# $NetBSD: Makefile,v 1.61 2020/11/05 09:08:31 ryoon Exp $

PKGNAME=	${DISTNAME:S/mozc-/mozc-server-/}
PKGREVISION=	27

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
