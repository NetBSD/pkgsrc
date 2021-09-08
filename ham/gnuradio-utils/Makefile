# $NetBSD: Makefile,v 1.32 2021/09/08 21:05:14 nia Exp $

PKGNAME=	gnuradio-utils-${VERSION}
PKGREVISION=	1
COMMENT=	Utilities in GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

DEPENDS+=	${PYPKGPREFIX}-qwt-qt5-[0-9]*:../../x11/py-qwt-qt5
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-plugins-[0-9]*:../../devel/py-click-plugins

#CONF_FILES+=	${EGDIR}/modtool.conf	${PKG_SYSCONFDIR}/modtool.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_BLOCKTOOL=ON
CMAKE_ARGS+=	-DENABLE_GR_MODTOOL=ON
CMAKE_ARGS+=	-DENABLE_GR_UTILS=ON

.include	"../../devel/SDL/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
