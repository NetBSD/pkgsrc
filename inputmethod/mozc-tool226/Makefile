# $NetBSD: Makefile,v 1.4 2024/05/16 06:15:05 wiz Exp $

PKGNAME=	${DISTNAME:S/mozc-/mozc-tool-/}
PKGREVISION=	27

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

.include "../../inputmethod/mozc-server226/Makefile.common"
.include "../../mk/bsd.pkg.mk"
