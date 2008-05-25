# $NetBSD: Makefile,v 1.13 2008/05/25 21:23:26 wiz Exp $
#

DISTNAME=	ntfs-3g-1.1120
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	http://www.ntfs-3g.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ntfs-3g.org/
COMMENT=	NTFS driver for Linux/FreeBSD/NetBSD with read and write support

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
