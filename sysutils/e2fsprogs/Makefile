# $NetBSD: Makefile,v 1.5 2003/04/14 23:15:54 hubertf Exp $
#

DISTNAME=	e2fsprogs-1.32
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=e2fsprogs/} \
		ftp://ftp.dei.uc.pt/.d4/linuxberg/files/console/system/ \
		ftp://tsx-11.mit.edu/pub/linux/packages/ext2fs/ \
		ftp://ftp.gwdg.de/pub/linux/mirrors/tsx-11/packages/ext2fs/

MAINTAINER=	hubert.feyrer@rz.uni-regensburg.de
HOMEPAGE=	http://web.mit.edu/tytso/www/linux/e2fsprogs.html
COMMENT=	Second extended file system (ext2fs) management programs

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=--disable-fsck
.endif

.include "../../mk/bsd.pkg.mk"
