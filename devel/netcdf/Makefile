# $NetBSD: Makefile,v 1.19 2004/10/03 00:13:31 tv Exp $

DISTNAME=	netcdf-3.5.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://www.gfd-dennou.org/arch/netcdf/unidata-mirror/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.unidata.ucar.edu/packages/netcdf/index.html
COMMENT=	Library for array-oriented data access

WRKSRC=			${WRKDIR}/${DISTNAME}/src
USE_BUILDLINK3=		yes
USE_FORTRAN=		# defined
USE_GCC_SHLIB=		# defined
USE_LIBTOOL=		# defined
GNU_CONFIGURE=		# defined
CPPFLAGS+=		-Df2cFortran -Dunix

.include "../../mk/bsd.pkg.mk"
