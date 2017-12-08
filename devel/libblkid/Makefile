# $NetBSD: Makefile,v 1.4 2017/12/08 08:03:35 adam Exp $

.include "../../devel/libuuid/Makefile.common"

PKGNAME=	${DISTNAME:S/util-linux/libblkid/}
CATEGORIES=	devel
COMMENT=	Library to handle device identification and token extraction
LICENSE=	gnu-lgpl-v2.1

CONFIGURE_ARGS+=	--enable-libblkid
PKGCONFIG_OVERRIDE+=	libblkid/blkid.pc.in

#.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
