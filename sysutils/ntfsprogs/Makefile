# $NetBSD: Makefile,v 1.1.1.1 2004/10/05 12:39:38 agc Exp $
#

DISTNAME=	ntfsprogs-1.9.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linux-ntfs/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://linux-ntfs.sourceforge.net/
COMMENT=	Linux-NTFS project utilities for the Windows NT Filesystem (ntfs)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=--enable-debug

# XXX support for this should be possibly integrated with other
# gnome pkgsrc and this could be a configurable option
CONFIGURE_ARGS+=--disable-gnome-vfs

.include "../../mk/bsd.pkg.mk"
