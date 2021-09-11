# $NetBSD: Makefile,v 1.2 2021/09/11 15:40:23 fcambus Exp $

DISTNAME=	mold-0.9.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rui314/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/rui314/mold/
COMMENT=	High performance drop-in replacement for existing Unix linkers
LICENSE=	gnu-agpl-v3

ONLY_FOR_PLATFORM=	Linux-*-x86_64

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

MAKE_FLAGS+=	MAN_DIR="${PREFIX}/${PKGMANDIR}"
MAKE_FLAGS+=	SYSTEM_MIMALLOC=1 SYSTEM_TBB=1

.include "../../devel/mimalloc/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
