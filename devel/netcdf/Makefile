# $NetBSD: Makefile,v 1.6 2001/02/16 14:38:43 wiz Exp $
#

DISTNAME=	netcdf-3.4
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		ftp://ftp.dfd.dlr.de/pub/ucar/netcdf/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.unidata.ucar.edu/packages/netcdf/index.html
COMMENT=	Library for array-oriented data access

USE_FORTRAN=	# defined
USE_LIBTOOL=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CPPFLAGS="-Df2cFortran -Dunix"

.include "../../mk/bsd.pkg.mk"
