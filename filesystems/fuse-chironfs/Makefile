# $NetBSD: Makefile,v 1.5 2012/10/03 16:08:30 asau Exp $
#

DISTNAME=	chironfs-1.1.1
PKGNAME=	fuse-chironfs-1.1.1
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	http://chironfs.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/chironfs/
COMMENT=	Replicating file system

GNU_CONFIGURE=	yes

LDFLAGS.DragonFly+=	-lpthread

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
