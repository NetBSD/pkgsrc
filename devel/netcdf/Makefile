# $NetBSD: Makefile,v 1.32 2012/10/31 11:17:32 asau Exp $

DISTNAME=	netcdf-4.1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.unidata.ucar.edu/downloads/netcdf/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	Library for array-oriented data access

USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-f90
CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-netcdf-4

INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
