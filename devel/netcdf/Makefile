# $NetBSD: Makefile,v 1.24 2006/03/04 21:29:18 jlam Exp $

DISTNAME=	netcdf-3.6.0-p1
PKGNAME=	netcdf-3.6.0p1
CATEGORIES=	devel
MASTER_SITES=	ftp://www.gfd-dennou.org/arch/netcdf/unidata-mirror/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unidata.ucar.edu/packages/netcdf/index.html
COMMENT=	Library for array-oriented data access

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-Df2cFortran -Dunix

.include "../../mk/bsd.pkg.mk"
