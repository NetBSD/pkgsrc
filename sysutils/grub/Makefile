# $NetBSD: Makefile,v 1.2 2002/04/11 20:03:09 magick Exp $
#

DISTNAME=	grub-0.91
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=	jgoerzen@complete.org
HOMEPAGE=	http://www.gnu.org/software/grub/
COMMENT=	GRand Unified Bootloader -- Boots *BSD, Linux, groks ffs, FAT, ext2

ONLY_FOR_PLATFORM=      NetBSD-1.5[Y-Z]*-i386 NetBSD-1.[6-9]*-i386
	# This package needs a new gas and therefore the -current
	# toolchain. Also it is only available for i386

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
