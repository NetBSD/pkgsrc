# $NetBSD: Makefile,v 1.8 2003/12/04 05:22:35 reed Exp $
#

DISTNAME=	e2fsprogs-1.32
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=e2fsprogs/} \
		ftp://ftp.dei.uc.pt/.d4/linuxberg/files/console/system/ \
		ftp://tsx-11.mit.edu/pub/linux/packages/ext2fs/ \
		ftp://ftp.gwdg.de/pub/linux/mirrors/tsx-11/packages/ext2fs/

MAINTAINER=	hubert.feyrer@rz.uni-regensburg.de
HOMEPAGE=	http://e2fsprogs.sourceforge.net/
COMMENT=	Second extended file system (ext2fs) management programs

GNU_CONFIGURE=	yes
USE_MAKEINFO=	YES
INFO_FILES=	libext2fs.info

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=--disable-fsck
.endif

.include "../../mk/bsd.pkg.mk"
