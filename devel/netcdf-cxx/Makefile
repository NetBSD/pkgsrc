# $NetBSD: Makefile,v 1.2 2016/03/05 11:27:45 jperkin Exp $

DISTNAME=	netcdf-cxx-4.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.unidata.ucar.edu/downloads/netcdf/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	C++ support for NetCDF.

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
