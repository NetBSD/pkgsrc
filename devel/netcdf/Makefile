# $NetBSD: Makefile,v 1.82 2026/05/14 16:40:46 ryoon Exp $

DISTNAME=	netcdf-c-4.10.0
PKGNAME=	${DISTNAME:S/-c-/-/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Unidata/}
GITHUB_PROJECT=	netcdf-c
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.unidata.ucar.edu/software/netcdf
COMMENT=	Library for array-oriented data access
LICENSE=	modified-bsd

USE_TOOLS+=		m4 gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen
CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--enable-logging
TEST_TARGET=		check

CHECK_PORTABILITY_SKIP+=	ncdap_test/testbasicauth.sh

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
