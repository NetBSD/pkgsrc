# $NetBSD: Makefile,v 1.2 2000/11/11 17:49:28 tron Exp $
#

DISTNAME=	e2fsprogs-1.19
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=e2fsprogs/} \
		ftp://ftp.dei.uc.pt/.d4/linuxberg/files/console/system/ \
		ftp://tsx-11.mit.edu/pub/linux/packages/ext2fs/ \
		ftp://ftp.gwdg.de/pub/linux/mirrors/tsx-11/packages/ext2fs/

MAINTAINER=	hubert.feyrer@rz.uni-regensburg.de
HOMEPAGE=	http://web.mit.edu/tytso/www/linux/e2fsprogs.html

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-fsck

.include "../../mk/bsd.pkg.mk"
