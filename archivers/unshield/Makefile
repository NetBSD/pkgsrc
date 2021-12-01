# $NetBSD: Makefile,v 1.12 2021/12/01 09:34:13 adam Exp $

DISTNAME=	unshield-1.5.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=twogood/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twogood/unshield
COMMENT=	Extract InstallShield .CAB files
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DBUILD_SHARED=ON

LDFLAGS+=	-liconv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
