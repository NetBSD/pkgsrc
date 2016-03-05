# $NetBSD: Makefile,v 1.4 2016/03/05 11:27:46 jperkin Exp $

DISTNAME=	netcdf-fortran-4.2
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.unidata.ucar.edu/downloads/netcdf/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	Fortran support for NetCDF.

USE_LANGUAGES=		c fortran77
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "options.mk"

.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
