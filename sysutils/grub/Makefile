# $NetBSD: Makefile,v 1.1.1.1 2002/04/11 19:53:25 magick Exp $
#

DISTNAME=	grub-0.91
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=	jgoerzen@complete.org
HOMEPAGE=	http://www.gnu.org/software/grub/
COMMENT=	GRand Unified Bootloader -- Boots *BSD, Linux, groks ffs, FAT, ext2

ONLY_FOR_PLATFORM=      NetBSD-1.5[Y-Z]*-i386 NetBSD-1.[6-9]*-i386

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
