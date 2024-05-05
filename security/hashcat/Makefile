# $NetBSD: Makefile,v 1.4 2024/05/05 11:33:12 gdt Exp $

DISTNAME=	hashcat-6.2.6
CATEGORIES=	security
MASTER_SITES=	https://hashcat.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hashcat.net/
COMMENT=	World's fastest and most advanced password recovery utility
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake gsed
BUILD_TARGET=	hashcat
MAKE_ENV+=	SHARED=1
MAKE_ENV+=	USE_SYSTEM_ZLIB=1
MAKE_ENV+=	USE_SYSTEM_XXHASH=1

.include "../../mk/bsd.fast.prefs.mk"
# see include/common.h
BROKEN_ON_PLATFORM+=	${BIGENDIANPLATFORMS}

.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
