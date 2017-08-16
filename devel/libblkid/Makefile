# $NetBSD: Makefile,v 1.3 2017/08/16 20:45:35 wiz Exp $
#

DISTNAME=	util-linux-ng-2.18
PKGNAME=	libblkid-2.18
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/util-linux-ng/v2.18/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://kernel.org/~kzak/util-linux-ng/
COMMENT=	Library to handle device identification and token extraction
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
PKGCONFIG_OVERRIDE+=	shlibs/blkid/blkid.pc.in

CONFIGURE_ARGS+=	--without-ncurses
CONFIGURE_ARGS+=	--disable-mount
CONFIGURE_ARGS+=	--disable-fsck
CONFIGURE_ARGS+=	--disable-libuuid
CONFIGURE_ARGS+=	--disable-uuidd
CONFIGURE_ARGS+=	--disable-libmount
CONFIGURE_ARGS+=	--disable-agetty
CONFIGURE_ARGS+=	--disable-cramfs
CONFIGURE_ARGS+=	--disable-switch_root
CONFIGURE_ARGS+=	--disable-pivot_root
CONFIGURE_ARGS+=	--disable-fallocate
CONFIGURE_ARGS+=	--disable-unshare
CONFIGURE_ARGS+=	--disable-rename
CONFIGURE_ARGS+=	--disable-schedutils
CONFIGURE_ARGS+=	--disable-wall

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
