# $NetBSD: Makefile,v 1.18 2003/09/28 09:13:58 jlam Exp $
#

DISTNAME=	grub-0.93
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/grub/
COMMENT=	GRand Unified Bootloader -- Boots *BSD, Linux, groks ffs, FAT, ext2

ONLY_FOR_PLATFORM=	*-*-i386

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_BUILDLINK2=		YES

INFO_FILES=		grub.info

.include "../../mk/bsd.prefs.mk"

.if defined(GRUB_NETWORK_CARDS)
BUILD_DEFS+=		GRUB_NETWORK_CARDS
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

.if defined(GRUB_SCAN_ARGS)
CONFIGURE_ARGS+=	${GRUB_SCAN_ARGS}
.endif

.include "../../devel/binutils/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
