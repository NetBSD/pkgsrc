# $NetBSD: Makefile,v 1.6 2026/03/25 23:36:34 gdt Exp $

DISTNAME=		iodine-0.8.0
CATEGORIES=		net
MASTER_SITES=		https://code.kryo.se/iodine/

MAINTAINER=		gdt@NetBSD.org
#MAINTAINER+=		mwilhelmy@users.sourceforge.net
HOMEPAGE=		https://code.kryo.se/iodine/
COMMENT=		Tool to tunnel IPv4 over DNS
LICENSE=		mit

PKG_USERS=		iodine:iodine
PKG_GROUPS=		iodine

BUILD_DEFS+=		VARBASE
MAKE_DIRS=		${VARBASE}/chroot
OWN_DIRS=		${VARBASE}/chroot/iodine
MAKE_FLAGS+=		prefix=${PREFIX}
MAKE_FLAGS+=		mandir=${PREFIX}/${PKGMANDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
