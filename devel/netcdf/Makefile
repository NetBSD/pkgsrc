# $NetBSD: Makefile,v 1.4 2000/06/01 11:23:24 rh Exp $
#

DISTNAME=	netcdf-3.4
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		ftp://ftp.dfd.dlr.de/pub/ucar/netcdf/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.unidata.ucar.edu/packages/netcdf/index.html

CONFIGURE_ENV+=	CPPFLAGS="-Df2cFortran -Dunix"

USE_FORTRAN=	yes
USE_PKGLIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
