# $NetBSD: Makefile,v 1.6 2017/08/01 17:02:55 wiz Exp $

DISTNAME=	chironfs-1.1.1
PKGNAME=	fuse-chironfs-1.1.1
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	http://chironfs.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/chironfs/
COMMENT=	Replicating file system
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

LDFLAGS.DragonFly+=	-lpthread

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
