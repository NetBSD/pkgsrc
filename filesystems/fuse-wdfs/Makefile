# $NetBSD: Makefile,v 1.28 2024/05/16 06:14:51 wiz Exp $
#

DISTNAME=	wdfs-1.4.2
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	22
CATEGORIES=	filesystems
MASTER_SITES=	http://noedler.de/projekte/wdfs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://noedler.de/projekte/wdfs/
COMMENT=	FUSE-based webdav filesystem
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

PTHREAD_AUTO_VARS=	yes

.if exists(/usr/include/stdbool.h)
CPPFLAGS+=	-DHAVE_STDBOOL_H
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
