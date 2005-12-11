# $NetBSD: Makefile,v 1.3 2005/12/11 11:47:27 wulf Exp $

VERSION=	0.4
DISTNAME=	gr-wxgui-${VERSION}
PKGNAME=	gnuradio-wxgui-${VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}
COMMENT=	GUI framework for GNU Radio based on wxPython

PYTHON_PATCH_SCRIPTS+=	src/python/fftsink.py
PYTHON_PATCH_SCRIPTS+=	src/python/form.py
PYTHON_PATCH_SCRIPTS+=	src/python/powermate.py
PYTHON_PATCH_SCRIPTS+=	src/python/scopesink.py
PYTHON_PATCH_SCRIPTS+=	src/python/slider.py
PYTHON_PATCH_SCRIPTS+=	src/python/waterfallsink.py

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
