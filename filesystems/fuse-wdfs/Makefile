# $NetBSD: Makefile,v 1.1.1.1 2007/05/16 19:56:37 agc Exp $
#

DISTNAME=	wdfs-1.4.1
PKGNAME=	fuse-${DISTNAME}
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
