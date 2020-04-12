# $NetBSD: Makefile,v 1.10 2020/04/12 08:28:37 adam Exp $
#

DISTNAME=	fuse-darling-dmg-20160310
PKGREVISION=	9
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=darlinghq/}
GITHUB_PROJECT=	darling-dmg
GITHUB_TAG=	b7ce87bfe59c2ed758165c8650402f6d4c84d184

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/darlinghq/darling-dmg
COMMENT=	FUSE module for .dmg files (containing an HFS+ filesystem)
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../devel/cmake/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
