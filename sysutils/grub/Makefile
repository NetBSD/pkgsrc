# $NetBSD: Makefile,v 1.6 2002/04/30 16:10:20 wiz Exp $
#

DISTNAME=	grub-0.92
CATEGORIES=	sysutils
MASTER_SITES=	ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=	jgoerzen@complete.org
HOMEPAGE=	http://www.gnu.org/software/grub/
COMMENT=	GRand Unified Bootloader -- Boots *BSD, Linux, groks ffs, FAT, ext2

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../devel/binutils/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
