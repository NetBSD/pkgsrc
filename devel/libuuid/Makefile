# $NetBSD: Makefile,v 1.6 2014/02/12 11:44:58 fhajny Exp $

DISTNAME=	util-linux-2.19.1
PKGNAME=	${DISTNAME:S/util-linux/libuuid/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/linux/utils/util-linux/v2.19/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kernel.org/~kzak/util-linux-ng/
COMMENT=	Generate unique identifiers for objects
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-agetty
CONFIGURE_ARGS+=	--disable-cramfs
CONFIGURE_ARGS+=	--disable-fallocate
CONFIGURE_ARGS+=	--disable-fsck
CONFIGURE_ARGS+=	--disable-mount
CONFIGURE_ARGS+=	--disable-libblkid
CONFIGURE_ARGS+=	--disable-libmount
CONFIGURE_ARGS+=	--disable-pivot_root
CONFIGURE_ARGS+=	--disable-rename
CONFIGURE_ARGS+=	--disable-schedutils
CONFIGURE_ARGS+=	--disable-switch_root
CONFIGURE_ARGS+=	--disable-unshare
CONFIGURE_ARGS+=	--disable-uuidd
CONFIGURE_ARGS+=	--disable-wall
CONFIGURE_ARGS+=	--without-ncurses

PKGCONFIG_OVERRIDE+=	shlibs/uuid/uuid.pc.in

BUILD_DIRS=		include shlibs/uuid

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=../../../shlibs/uuid/src/uuid.sym
.endif

.include "../../mk/bsd.pkg.mk"
