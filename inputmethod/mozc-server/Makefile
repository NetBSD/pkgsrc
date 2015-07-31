# $NetBSD: Makefile,v 1.23 2015/07/31 13:07:05 ryoon Exp $

PKGNAME=	${DISTNAME:S/mozc-/mozc-server-/}

INSTALLATION_DIRS+=	libexec

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c ${MOZC_BUILD_MODE} \
		${_MAKE_JOBS} \
			server/server.gyp:mozc_server

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/${MOZC_BUILD_MODE}/mozc_server \
		${DESTDIR}${PREFIX}/libexec/mozc_server

.include "../../inputmethod/mozc-server/Makefile.common"
