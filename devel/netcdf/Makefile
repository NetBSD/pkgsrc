# $NetBSD: Makefile,v 1.33 2013/04/09 15:57:28 adam Exp $

DISTNAME=	netcdf-4.2.1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.unidata.ucar.edu/downloads/netcdf/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	Library for array-oriented data access

USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen
CONFIGURE_ARGS+=	--disable-examples

INFO_FILES=		yes

.include "../../devel/hdf5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
