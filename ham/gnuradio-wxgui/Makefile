# $NetBSD: Makefile,v 1.8 2006/05/18 20:29:59 wiz Exp $

VERSION=	0.6
DISTNAME=	gr-wxgui-${VERSION}
PKGNAME=	gnuradio-wxgui-${VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}
COMMENT=	GUI framework for GNU Radio based on wxPython

BROKEN_IN=	pkgsrc-2006Q1

PYTHON_PATCH_SCRIPTS+=	src/python/fftsink.py
PYTHON_PATCH_SCRIPTS+=	src/python/form.py
PYTHON_PATCH_SCRIPTS+=	src/python/powermate.py
PYTHON_PATCH_SCRIPTS+=	src/python/scopesink.py
PYTHON_PATCH_SCRIPTS+=	src/python/slider.py
PYTHON_PATCH_SCRIPTS+=	src/python/waterfallsink.py

.include "../../meta-pkgs/gnuradio/Makefile.common"

CONF_FILES+=    ${EGDIR}/gr-wxgui.conf ${PKG_SYSCONFDIR}/gr-wxgui.conf
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/share/examples

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
