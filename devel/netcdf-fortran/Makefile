# $NetBSD: Makefile,v 1.30 2024/05/16 06:14:47 wiz Exp $

DISTNAME=	netcdf-fortran-4.2
PKGREVISION=	27
CATEGORIES=	devel
MASTER_SITES=	https://www.unidata.ucar.edu/downloads/netcdf/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	Fortran support for NetCDF

USE_LANGUAGES=		c fortran77
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "options.mk"

.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
