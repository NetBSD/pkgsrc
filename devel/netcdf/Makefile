# $NetBSD: Makefile,v 1.22 2005/02/25 09:52:47 adam Exp $

DISTNAME=	netcdf-3.6.0-p1
PKGNAME=	netcdf-3.6.0p1
CATEGORIES=	devel
MASTER_SITES=	ftp://www.gfd-dennou.org/arch/netcdf/unidata-mirror/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.unidata.ucar.edu/packages/netcdf/index.html
COMMENT=	Library for array-oriented data access

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-Df2cFortran -Dunix

.include "../../mk/bsd.pkg.mk"
