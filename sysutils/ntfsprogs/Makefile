# $NetBSD: Makefile,v 1.3 2006/01/26 21:43:51 adam Exp $

DISTNAME=	ntfsprogs-1.12.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linux-ntfs/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://linux-ntfs.sourceforge.net/
COMMENT=	Linux-NTFS project utilities for the Windows NT Filesystem

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-debug

# XXX support for this should be possibly integrated with other
# gnome pkgsrc and this could be a configurable option
CONFIGURE_ARGS+=	--disable-gnome-vfs

GCC_REQD+=	2.96

.include "../../mk/bsd.pkg.mk"
