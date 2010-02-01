# $NetBSD: Makefile,v 1.1.1.1 2010/02/01 13:36:43 jmmv Exp $
#

DISTNAME=	bindfs-1.8.4
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	http://bindfs.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/bindfs/
COMMENT=	Remounts file system subtrees in arbitrary locations
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf gmake pkg-config

CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
