# $NetBSD: Makefile,v 1.69 2024/05/16 06:14:47 wiz Exp $

DISTNAME=	netcdf-c-4.9.2
PKGNAME=	${DISTNAME:S/-c-/-/}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://downloads.unidata.ucar.edu/netcdf-c/4.9.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unidata.ucar.edu/software/netcdf/index.html
COMMENT=	Library for array-oriented data access
LICENSE=	modified-bsd

USE_TOOLS+=		m4 gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen
CONFIGURE_ARGS+=	--disable-examples

#post-install:
#	rm ${DESTDIR}${PREFIX}/lib/libbzip2.*

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
