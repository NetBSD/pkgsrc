# $NetBSD: Makefile,v 1.3 2001/02/17 17:42:12 wiz Exp $
#

DISTNAME=	e2fsprogs-1.19
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=e2fsprogs/} \
		ftp://ftp.dei.uc.pt/.d4/linuxberg/files/console/system/ \
		ftp://tsx-11.mit.edu/pub/linux/packages/ext2fs/ \
		ftp://ftp.gwdg.de/pub/linux/mirrors/tsx-11/packages/ext2fs/

MAINTAINER=	hubert.feyrer@rz.uni-regensburg.de
HOMEPAGE=	http://web.mit.edu/tytso/www/linux/e2fsprogs.html
COMMENT=	Second extended file system (ext2fs) management programs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-fsck

.include "../../mk/bsd.pkg.mk"
