# $NetBSD: Makefile,v 1.73 2023/01/03 17:37:40 wiz Exp $

PKGNAME=	${DISTNAME:S/mozc-/mozc-tool-/}
PKGREVISION=	12

INSTALLATION_DIRS+=	libexec

ALL_ENV+=	qt_dir=${QTDIR}

pre-configure:
	${RM} ${WRKSRC}/unix/uim/uim.gyp

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c ${MOZC_BUILD_MODE} \
			gui/gui.gyp:mozc_tool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/${MOZC_BUILD_MODE}/mozc_tool \
		${DESTDIR}${PREFIX}/libexec

.include "../../inputmethod/mozc-server/Makefile.common"
.include "../../mk/bsd.pkg.mk"
