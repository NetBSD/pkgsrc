# $NetBSD: Makefile,v 1.1 2024/02/10 01:20:46 ryoon Exp $

PKGNAME=	${DISTNAME:S/mozc-/mozc-server-/}
PKGREVISION=	25

INSTALLATION_DIRS+=	libexec

post-patch:
	${RM} ${WRKSRC}/unix/uim/uim.gyp

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build \
		-c ${MOZC_BUILD_MODE} \
			dictionary/dictionary_base.gyp:text_dictionary_loader \
			server/server.gyp:mozc_server

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/${MOZC_BUILD_MODE}/mozc_server \
		${DESTDIR}${PREFIX}/libexec/mozc_server

.include "../../inputmethod/mozc-server226/Makefile.common"
.include "../../mk/bsd.pkg.mk"
