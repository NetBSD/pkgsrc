# $NetBSD: Makefile,v 1.32 2005/05/09 17:35:16 xtraeme Exp $
#

DISTNAME=	grub-0.97
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/grub/
COMMENT=	GRand Unified Bootloader -- Boots *BSD, Linux, groks ffs, FAT, ext2

ONLY_FOR_PLATFORM=	*-*-i386

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

INFO_FILES=		grub.info multiboot.info

BUILDLINK_TRANSFORM+=	rename:-fno-builtin:-ffreestanding

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		GRUB_NETWORK_CARDS
BUILD_DEFS+=		GRUB_PRESET_COMMAND
BUILD_DEFS+=		GRUB_SCAN_ARGS

.if defined(GRUB_NETWORK_CARDS)
CONFIGURE_ARGS+=	--enable-diskless
PLIST_SUBST+=		NETBOOT=

.for GRUB_NETWORK_CARD in ${GRUB_NETWORK_CARDS}
CONFIGURE_ARGS+=	--enable-${GRUB_NETWORK_CARD}
.endfor

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/grub
	${INSTALL_DATA} ${WRKSRC}/netboot/README.netboot \
		${PREFIX}/share/doc/grub
.else
PLIST_SUBST+=		NETBOOT="@comment "
.endif

.if defined(GRUB_PRESET_COMMAND) && !empty(GRUB_PRESET_COMMAND)
CONFIGURE_ARGS+=	--enable-preset-menu=${WRKSRC}/presetmenu

post-extract:
	${ECHO} ${GRUB_PRESET_COMMAND} > ${WRKSRC}/presetmenu
.endif

.if defined(GRUB_SCAN_ARGS)
CONFIGURE_ARGS+=	${GRUB_SCAN_ARGS}
.endif

.include "../../devel/binutils/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
