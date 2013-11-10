# $NetBSD: Makefile,v 1.3 2013/11/10 06:36:28 apb Exp $
#

DISTNAME=	bindfs-1.8.4
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	http://bindfs.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/bindfs/
COMMENT=	Remounts file system subtrees in arbitrary locations
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf gmake pkg-config

CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
