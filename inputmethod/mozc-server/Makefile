# $NetBSD: Makefile,v 1.2 2013/01/22 11:15:28 ryoon Exp $
#

PKGNAME=	${DISTNAME:S/mozc-/mozc-server-/}

INSTALLATION_DIRS+=	libexec

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c Release ${_MAKE_JOBS} \
			server/server.gyp:mozc_server

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/Release/mozc_server \
		${DESTDIR}${PREFIX}/libexec/mozc_server_japanese

.include "../../inputmethod/ibus-mozc/Makefile.common"
