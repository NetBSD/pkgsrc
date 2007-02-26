# $NetBSD: Makefile,v 1.1.1.1 2007/02/26 19:55:28 pooka Exp $
#

DISTNAME=	ntfs-3g-1.0
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	http://www.ntfs-3g.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ntfs-3g.org/
COMMENT=	NTFS driver for Linux/FreeBSD/NetBSD with read and write support

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf gmake pkg-config

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
