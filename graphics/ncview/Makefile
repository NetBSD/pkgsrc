# $NetBSD: Makefile,v 1.1.1.1 2001/02/09 23:41:34 jtb Exp $

DISTNAME=		ncview-1.92b
CATEGORIES=		graphics
MASTER_SITES=		ftp://cirrus.ucsd.edu/pub/ncview/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://meteora.ucsd.edu/~pierce/ncview_home_page.html

DEPENDS+=		netcdf>=3.4:../../devel/netcdf
DEPENDS+=		udunits>=1.11.7:../../math/udunits

GNU_CONFIGURE=		yes
USE_XAW=		yes
USE_X11BASE=		yes

EVAL_PREFIX+=		NETCDF=netcdf UDUNITS=udunits

CONFIGURE_ARGS+=	--with-netcdf_incdir=${NETCDF}/include
CONFIGURE_ARGS+=	--with-netcdf_libdir=${NETCDF}/lib
CONFIGURE_ARGS+=	--with-udunits_incdir=${UDUNITS}/include
CONFIGURE_ARGS+=	--with-udunits_libdir=${UDUNITS}/lib

.include "../../mk/bsd.pkg.mk"
