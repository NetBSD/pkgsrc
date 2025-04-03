# $NetBSD: Makefile,v 1.17 2025/04/03 07:14:13 adam Exp $

DISTNAME=	unshield-1.6.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=twogood/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twogood/unshield
COMMENT=	Extract InstallShield .CAB files
LICENSE=	mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED=ON

LDFLAGS+=	-liconv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
