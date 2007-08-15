# $NetBSD: Makefile,v 1.5 2007/08/15 13:53:57 xtraeme Exp $
#

DISTNAME=	ntfs-3g-1.810
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	http://www.ntfs-3g.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.ntfs-3g.org/
COMMENT=	NTFS driver for Linux/FreeBSD/NetBSD with read and write support

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf gmake pkg-config

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
