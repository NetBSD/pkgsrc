# $NetBSD: Makefile,v 1.11 2020/01/18 21:48:40 jperkin Exp $

DISTNAME=	unshield-1.4.3
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=twogood/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twogood/unshield
COMMENT=	Extract InstallShield .CAB files
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

LDFLAGS+=	-liconv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
