# $NetBSD: Makefile,v 1.3 2013/01/26 20:33:59 ryoon Exp $
#

PKGNAME=	${DISTNAME:S/mozc-/mozc-server-/}
PKGREVISION=	1

INSTALLATION_DIRS+=	libexec

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c Release ${_MAKE_JOBS} \
			server/server.gyp:mozc_server

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/Release/mozc_server \
		${DESTDIR}${PREFIX}/libexec/mozc_server_japanese

.include "../../inputmethod/ibus-mozc/Makefile.common"
