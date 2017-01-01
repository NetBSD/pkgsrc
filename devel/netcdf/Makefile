# $NetBSD: Makefile,v 1.40 2017/01/01 16:05:57 adam Exp $

DISTNAME=	netcdf-4.2.1.1
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://www.unidata.ucar.edu/downloads/netcdf/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	Library for array-oriented data access

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen
CONFIGURE_ARGS+=	--disable-examples

.include "../../devel/hdf5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
