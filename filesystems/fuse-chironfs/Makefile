# $NetBSD: Makefile,v 1.4 2012/08/17 13:02:49 marino Exp $
#

DISTNAME=	chironfs-1.1.1
PKGNAME=	fuse-chironfs-1.1.1
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	http://chironfs.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/chironfs/
COMMENT=	Replicating file system

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

LDFLAGS.DragonFly+=	-lpthread

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
