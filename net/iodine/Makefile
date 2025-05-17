# $NetBSD: Makefile,v 1.5 2025/05/17 19:10:51 zafer Exp $

DISTNAME=		iodine-0.7.0
CATEGORIES=		net
MASTER_SITES=		https://code.kryo.se/iodine/

MAINTAINER=		mwilhelmy@users.sourceforge.net
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
