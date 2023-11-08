# $NetBSD: Makefile,v 1.28 2023/11/08 13:18:57 wiz Exp $

DISTNAME=	netcdf-cxx4-4.3.1
PKGNAME=	${DISTNAME:S/cxx4/cxx/}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://downloads.unidata.ucar.edu/netcdf-cxx/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	C++ support for NetCDF
#LICENSE=	NetCDF copyright, See COPYRIGHT file

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes
TEST_TARGET=		check

.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
