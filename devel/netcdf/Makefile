# $NetBSD: Makefile,v 1.2 1999/04/05 03:56:33 hubertf Exp $
#

DISTNAME=	netcdf-3.4
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/netcdf/ \
		ftp://ftp.dfd.dlr.de/pub/ucar/netcdf/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.unidata.ucar.edu/packages/netcdf/index.html

.if ! exists(/usr/bin/fort77)
DEPENDS+=	fort77-1.14a:../../lang/fort77
.endif

CONFIGURE_ENV+=	CPPFLAGS="-Df2cFortran -Dunix"

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
