# $NetBSD: Makefile,v 1.15 2003/09/17 19:40:33 grant Exp $

DISTNAME=		ncview-1.92d
CATEGORIES=		graphics
MASTER_SITES=		ftp://cirrus.ucsd.edu/pub/ncview/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://meteora.ucsd.edu/~pierce/ncview_home_page.html
COMMENT=		Visual browser for netCDF format files

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_X11BASE=		yes

CONFIGURE_ARGS+=	--with-netcdf_incdir=${BUILDLINK_PREFIX.netcdf}/include
CONFIGURE_ARGS+=	--with-netcdf_libdir=${BUILDLINK_PREFIX.netcdf}/lib
CONFIGURE_ARGS+=	--with-udunits_incdir=${BUILDLINK_PREFIX.udunits}/include
CONFIGURE_ARGS+=	--with-udunits_libdir=${BUILDLINK_PREFIX.udunits}/lib

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
USE_PKGSRC_GCC=		# defined
.endif

.include "../../devel/netcdf/buildlink2.mk"
.include "../../math/udunits/buildlink2.mk"
.include "../../mk/xaw.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
