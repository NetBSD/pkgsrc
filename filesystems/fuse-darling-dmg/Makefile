# $NetBSD: Makefile,v 1.22 2024/05/29 16:32:28 adam Exp $
#

DISTNAME=	fuse-darling-dmg-1.0.4.20210411
PKGREVISION=	8
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=darlinghq/}
GITHUB_PROJECT=	darling-dmg
GITHUB_TAG=	34d3a346039f25a407c64aca1c7ecbdd9af85933

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/darlinghq/darling-dmg
COMMENT=	FUSE module for .dmg files (containing an HFS+ filesystem)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
