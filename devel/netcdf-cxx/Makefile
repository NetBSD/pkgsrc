# $NetBSD: Makefile,v 1.11 2018/12/13 19:51:33 adam Exp $

DISTNAME=	netcdf-cxx-4.2
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	https://www.unidata.ucar.edu/downloads/netcdf/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	C++ support for NetCDF.

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
