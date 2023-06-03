# $NetBSD: Makefile,v 1.25 2023/06/03 03:38:52 mef Exp $

DISTNAME=	netcdf-cxx4-4.3.1
PKGNAME=	${DISTNAME:S/cxx4/cxx/}
CATEGORIES=	devel
MASTER_SITES=	https://downloads.unidata.ucar.edu/netcdf-cxx/4.3.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	C++ support for NetCDF
#LICENSE=	NetCDF copyright, See COPYRIGHT file

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
