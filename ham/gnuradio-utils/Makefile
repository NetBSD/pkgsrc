# $NetBSD: Makefile,v 1.18 2019/07/01 04:08:25 ryoon Exp $

PKGNAME=	gnuradio-utils-${VERSION}
PKGREVISION=	1
COMMENT=	Utilities in GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

#BROKEN=		MatPlotLib requires Python 3.x.

#DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
#ONF_FILES+=	${EGDIR}/modtool.conf	${PKG_SYSCONFDIR}/modtool.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_UTILS=True

.include	"../../devel/SDL/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
