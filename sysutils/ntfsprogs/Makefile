# $NetBSD: Makefile,v 1.4 2006/03/03 10:15:46 adam Exp $

DISTNAME=	ntfsprogs-1.13.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linux-ntfs/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linux-ntfs.org/
COMMENT=	Linux-NTFS project utilities for the Windows NT Filesystem

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# XXX support for this should be possibly integrated with other
# gnome pkgsrc and this could be a configurable option
CONFIGURE_ARGS+=	--disable-gnome-vfs

GCC_REQD+=	2.96

.include "../../mk/bsd.pkg.mk"
