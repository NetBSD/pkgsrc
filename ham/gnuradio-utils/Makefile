# $NetBSD: Makefile,v 1.79 2025/02/27 13:49:54 adam Exp $

PKGNAME=	gnuradio-utils-${VERSION}
COMMENT=	Utilities in GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-plugins-[0-9]*:../../devel/py-click-plugins
DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-qwt-qt5-[0-9]*:../../x11/py-qwt-qt5
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_BLOCKTOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_MODTOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GR_UTILS=ON

REPLACE_PYTHON+=	gr-utils/plot_tools/*.py

.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
