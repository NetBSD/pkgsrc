# $NetBSD: Makefile,v 1.1.1.1 2005/04/17 12:56:01 hamajima Exp $
#

DISTNAME=	spca5xx-20050206
PKGNAME=	spcaview-0.3b
CATEGORIES=	graphics x11
MASTER_SITES=	http://mxhaard.free.fr/spca50x/Download/

PATCH_SITES=	http://www2.starcat.ne.jp/~takam/bsd/
PATCHFILES= 	spca5xx-bsd-0.3b.patch.gz
PATCH_DIST_STRIP=	-p3

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www2.starcat.ne.jp/~takam/bsd/NetBSD.html#spca561
COMMENT=	USB Cameras based SPCA5xx Utilities

WRKSRC=		${WRKDIR}/spca5xx-20050206/drivers/usb

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
