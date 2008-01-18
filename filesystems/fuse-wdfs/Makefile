# $NetBSD: Makefile,v 1.2 2008/01/18 05:06:33 tnn Exp $
#

DISTNAME=	wdfs-1.4.1
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	http://noedler.de/projekte/wdfs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://noedler.de/projekte/wdfs/
COMMENT=	FUSE-based webdav filesystem

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
