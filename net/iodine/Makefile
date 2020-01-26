# $NetBSD: Makefile,v 1.4 2020/01/26 17:31:50 rillig Exp $

DISTNAME=		iodine-0.7.0
CATEGORIES=		net
MASTER_SITES=		http://code.kryo.se/iodine/

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
