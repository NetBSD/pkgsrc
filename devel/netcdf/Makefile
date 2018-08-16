# $NetBSD: Makefile,v 1.50 2018/08/16 18:54:29 adam Exp $

DISTNAME=	netcdf-4.6.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://www.unidata.ucar.edu/downloads/netcdf/ftp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	Library for array-oriented data access

USE_TOOLS+=		m4
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen
CONFIGURE_ARGS+=	--disable-examples

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../devel/hdf5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
