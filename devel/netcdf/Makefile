# $NetBSD: Makefile,v 1.13 2003/05/29 23:14:08 grant Exp $

DISTNAME=	netcdf-3.5.0
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	devel
MASTER_SITES=	ftp://www.gfd-dennou.org/arch/netcdf/unidata-mirror/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.unidata.ucar.edu/packages/netcdf/index.html
COMMENT=	Library for array-oriented data access

USE_BUILDLINK2=		# defined
USE_FORTRAN=		# defined
USE_GCC_SHLIB=		# defined
USE_LIBTOOL=		# defined
GNU_CONFIGURE=		# defined
CPPFLAGS+=		-Df2cFortran -Dunix

.include "../../mk/bsd.pkg.mk"
