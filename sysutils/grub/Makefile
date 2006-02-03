# $NetBSD: Makefile,v 1.39 2006/02/03 09:59:32 jmmv Exp $
#

DISTNAME=	grub-0.97
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/grub/
COMMENT=	GRand Unified Bootloader -- Boots *BSD, Linux, groks ffs, FAT, ext2

ONLY_FOR_PLATFORM=	*-*-i386

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

INFO_FILES=		grub.info multiboot.info

BUILDLINK_TRANSFORM+=	rename:-fno-builtin:-ffreestanding

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		GRUB_NETWORK_CARDS
BUILD_DEFS+=		GRUB_PRESET_COMMAND
BUILD_DEFS+=		GRUB_SCAN_ARGS

.include "../../devel/binutils/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"

.if defined(GRUB_NETWORK_CARDS)
CONFIGURE_ARGS+=	--enable-diskless
PLIST_SUBST+=		NETBOOT=

.for GRUB_NETWORK_CARD in ${GRUB_NETWORK_CARDS}
CONFIGURE_ARGS+=	--enable-${GRUB_NETWORK_CARD}
.endfor

post-install: grub-netboot-install
grub-netboot-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/grub
	${INSTALL_DATA} ${WRKSRC}/netboot/README.netboot \
		${PREFIX}/share/doc/grub
.else
PLIST_SUBST+=		NETBOOT="@comment "
.endif

.if defined(GRUB_PRESET_COMMAND) && !empty(GRUB_PRESET_COMMAND)
CONFIGURE_ARGS+=	--enable-preset-menu=${WRKSRC}/presetmenu

post-extract: grub-presetmenu
grub-presetmenu:
	${ECHO} ${GRUB_PRESET_COMMAND} > ${WRKSRC}/presetmenu
.endif

.if defined(GRUB_SCAN_ARGS)
CONFIGURE_ARGS+=	${GRUB_SCAN_ARGS}
.endif

SUBST_CLASSES+=		grubterm
SUBST_STAGE.grubterm=	post-patch
SUBST_MESSAGE.grubterm=	"Changing references to <term.h> to <grubterm.h>"
SUBST_FILES.grubterm=	grub/*.c stage2/Makefile.in stage2/*.c
SUBST_SED.grubterm=	-e "s,<term.h>,<grubterm.h>,g"			\
			-e "s, term.h , grubterm.h ,g"

post-extract:
	${MV} ${WRKSRC}/stage2/term.h ${WRKSRC}/stage2/grubterm.h

.include "../../mk/bsd.pkg.mk"
