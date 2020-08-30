# $NetBSD: Makefile,v 1.23 2020/08/30 21:09:24 tnn Exp $

PKGNAME=	gnuradio-utils-${VERSION}
COMMENT=	Utilities in GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
#CONF_FILES+=	${EGDIR}/modtool.conf	${PKG_SYSCONFDIR}/modtool.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_GR_UTILS=ON

.include	"../../devel/SDL/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
