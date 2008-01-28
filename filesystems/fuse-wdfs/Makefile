# $NetBSD: Makefile,v 1.3 2008/01/28 02:56:46 bjs Exp $
#

DISTNAME=	wdfs-1.4.2
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	http://noedler.de/projekte/wdfs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://noedler.de/projekte/wdfs/
COMMENT=	FUSE-based webdav filesystem

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PTHREAD_AUTO_VARS= 	yes

.if exists(/usr/include/stdbool.h)
CPPFLAGS+=	-DHAVE_STDBOOL_H
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
