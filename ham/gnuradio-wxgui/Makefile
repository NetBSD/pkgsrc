# $NetBSD: Makefile,v 1.2 2005/10/11 11:27:35 wulf Exp $

VERSION=	0.3
DISTNAME=	gr-wxgui-${VERSION}
PKGNAME=	gnuradio-wxgui-${VERSION}
WRKSRC=		${WRKDIR}/${DISTNAME}
COMMENT=	GUI framework for GNU Radio based on wxPython

PY_PATHCH_SCRIPTS+=	src/python/fftsink.py
PY_PATHCH_SCRIPTS+=	src/python/scope.py
PY_PATHCH_SCRIPTS+=	src/python/slider.py
PY_PATHCH_SCRIPTS+=	src/python/waterfallsink.py

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
