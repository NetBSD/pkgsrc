# $NetBSD: Makefile,v 1.1 2024/09/13 19:35:15 adam Exp $

DISTNAME=	libjwt-1.17.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=benmcollins/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/benmcollins/libjwt
COMMENT=	JWT C library
LICENSE=	mpl-2.0

EXTRACT_USING=	gtar # Cannot restore extended attributes

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-doxygen-doc

# cmake does not produce .pc file.
#CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
#.include "../../devel/cmake/build.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
