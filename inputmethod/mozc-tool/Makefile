# $NetBSD: Makefile,v 1.6 2013/04/29 09:22:35 ryoon Exp $
#

PKGNAME=	${DISTNAME:S/mozc-/mozc-tool-/}

INSTALLATION_DIRS+=	libexec

ALL_ENV+=	qt_dir=${QTDIR}

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} \
		${PYTHONBIN} build_mozc.py build -c ${MOZC_BUILD_MODE} ${_MAKE_JOBS} \
			gui/gui.gyp:mozc_tool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out_${OSDEST}/${MOZC_BUILD_MODE}/mozc_tool \
		${DESTDIR}${PREFIX}/libexec

.include "../../inputmethod/ibus-mozc/Makefile.common"
