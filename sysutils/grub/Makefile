# $NetBSD: Makefile,v 1.23 2004/04/26 15:42:44 xtraeme Exp $
#

DISTNAME=	grub-0.94
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/grub/
COMMENT=	GRand Unified Bootloader -- Boots *BSD, Linux, groks ffs, FAT, ext2

ONLY_FOR_PLATFORM=	*-*-i386

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES

INFO_FILES=		grub.info multiboot.info

BUILDLINK_TRANSFORM+=	S:-fno-builtin:-ffreestanding:

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		GRUB_NETWORK_CARDS
BUILD_DEFS+=		GRUB_PRESET_COMMAND
BUILD_DEFS+=		GRUB_SCAN_ARGS
BUILD_DEFS+=		GRUB_ISO9660

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

# eltorito support for GRUB
.if defined(GRUB_ISO9660)
CONFIGURE_ARGS+=	--enable-iso9660
PATCHFILES+=		grub-0.94-iso9660.diff
PATCH_SITES+=		ftp://ftp.netbsd.org/pub/NetBSD/misc/xtraeme/	

PLIST_SUBST+=		ISO9660=

pre-configure:
	cd ${WRKSRC};                                           \
	${ACLOCAL};                                             \
	${AUTOHEADER};                                          \
	${AUTOMAKE} -a --foreign -i;                            \
	${AUTOCONF}
.include "../../mk/automake.mk"
.else
PLIST_SUBST+=		ISO9660="@comment "
.endif

.include "../../devel/binutils/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
