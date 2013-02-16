# $NetBSD: Makefile,v 1.5 2013/02/16 11:22:44 wiz Exp $
#

PKGNAME=	${DISTNAME:S/mozc-/mozc-tool-/}
PKGREVISION=	3

INSTALLATION_DIRS+=	libexec

.include "../../x11/qt4-libs/buildlink3.mk"

ALL_ENV+=	qt_dir=${QTDIR}

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c Release ${_MAKE_JOBS} \
			gui/gui.gyp:mozc_tool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/Release/mozc_tool \
		${DESTDIR}${PREFIX}/libexec

.include "../../inputmethod/ibus-mozc/Makefile.common"
