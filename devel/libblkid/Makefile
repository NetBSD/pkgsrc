# $NetBSD: Makefile,v 1.6 2019/04/04 07:34:07 bsiegert Exp $

.include "../../devel/libuuid/Makefile.common"

PKGNAME=	${DISTNAME:S/util-linux/libblkid/}
PKGREVISION=	1
CATEGORIES=	devel
COMMENT=	Library to handle device identification and token extraction
LICENSE=	gnu-lgpl-v2.1

CONFIGURE_ARGS+=	--enable-libblkid
PKGCONFIG_OVERRIDE+=	libblkid/blkid.pc.in

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
