# $NetBSD: Makefile,v 1.8 2002/07/20 12:42:36 tron Exp $

DISTNAME=	grub-0.92
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/grub/
COMMENT=	GRand Unified Bootloader -- Boots *BSD, Linux, groks ffs, FAT, ext2

ONLY_FOR_PLATFORM=	*-*-i386

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.prefs.mk"

.if defined(GRUB_NETWORK_CARDS)
BUILD_DEFS+=		GRUB_NETWORK_CARDS
CONFIGURE_ARGS+=	--enable-diskless
PLIST_SUBST+=		NETBOOT=

.for GRUB_NETWORK_CARD in ${GRUB_NETWORK_CARDS}
CONFIGURE_ARGS+=	--enable-${GRUB_NETWORK_CARD}
.endfor
.else
PLIST_SUBST+=		NETBOOT="@comment "
.endif

.if defined(GRUB_SCAN_ARGS)
CONFIGURE_ARGS+=	${GRUB_SCAN_ARGS}
.endif

.include "../../devel/binutils/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
