# $NetBSD: Makefile,v 1.5 2001/05/03 21:06:13 jtb Exp $

DISTNAME=		ncview-1.92c
CATEGORIES=		graphics
MASTER_SITES=		ftp://cirrus.ucsd.edu/pub/ncview/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://meteora.ucsd.edu/~pierce/ncview_home_page.html
COMMENT=		Visual browser for netCDF format files

DEPENDS+=		netcdf>=3.4:../../devel/netcdf
DEPENDS+=		udunits>=1.11.7:../../math/udunits

GNU_CONFIGURE=		yes
USE_XAW=		yes
USE_X11BASE=		yes

NETCDF_DEFAULT=		${LOCALBASE}
EVAL_PREFIX+=		NETCDF=netcdf
UDUNITS_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		UDUNITS=udunits

CONFIGURE_ARGS+=	--with-netcdf_incdir=${NETCDF}/include
CONFIGURE_ARGS+=	--with-netcdf_libdir=${NETCDF}/lib
CONFIGURE_ARGS+=	--with-udunits_incdir=${UDUNITS}/include
CONFIGURE_ARGS+=	--with-udunits_libdir=${UDUNITS}/lib

.include "../../mk/bsd.pkg.mk"
