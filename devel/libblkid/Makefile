# $NetBSD: Makefile,v 1.7 2024/12/28 14:10:56 wiz Exp $

.include "../../devel/libuuid/Makefile.common"

PKGNAME=	${DISTNAME:S/util-linux/libblkid/}
CATEGORIES=	devel
COMMENT=	Library to handle device identification and token extraction
LICENSE=	gnu-lgpl-v2.1

CONFIGURE_ARGS+=	--enable-libblkid
PKGCONFIG_OVERRIDE+=	libblkid/blkid.pc.in

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
