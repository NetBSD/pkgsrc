# $NetBSD: Makefile,v 1.1 2014/10/13 12:51:10 mef Exp $

PKGNAME=	gnuradio-utils-${VERSION}
COMMENT=	Utilities in GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
CONF_FILES+=	${EGDIR}/modtool.conf	${PKG_SYSCONFDIR}/modtool.conf

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_GR_UTILS=True

.include	"../../devel/SDL/buildlink3.mk"

.include	"../../mk/bsd.pkg.mk"
