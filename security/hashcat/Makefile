# $NetBSD: Makefile,v 1.1 2022/01/10 02:30:23 khorben Exp $

DISTNAME=	hashcat-6.2.5
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

post-install:
	${RM} ${DESTDIR}${PREFIX}/include/hashcat/sort_r.h.orig

.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
