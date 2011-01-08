# $NetBSD: Makefile,v 1.1.1.1 2011/01/08 20:40:33 markd Exp $
#

DISTNAME=	util-linux-ng-2.18
PKGNAME=	libuuid-2.18
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/util-linux-ng/v2.18/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kernel.org/~kzak/util-linux-ng/
COMMENT=	Generate unique identifiers for objects
LICENSE=	modified-bsd

CONFLICTS=	ossp-uuid-[0-9]* # libuuid.* uuid.pc uuid.3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
PKGCONFIG_OVERRIDE+=	shlibs/uuid/uuid.pc.in

CONFIGURE_ARGS+=	--without-ncurses
CONFIGURE_ARGS+=	--disable-mount
CONFIGURE_ARGS+=	--disable-fsck
CONFIGURE_ARGS+=	--disable-uuidd
CONFIGURE_ARGS+=	--disable-libblkid
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

.include "../../mk/bsd.pkg.mk"
