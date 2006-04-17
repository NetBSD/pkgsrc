# $NetBSD: Makefile,v 1.5 2006/04/17 13:46:36 wiz Exp $
#

DISTNAME=	spca5xx-20060301
PKGNAME=	spcaview-0.5a
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://mxhaard.free.fr/spca50x/Download/

PATCH_SITES=	http://www.medias.ne.jp/~takam/bsd/
PATCHFILES= 	spca5xx-bsd-0.5a.patch.gz
PATCH_DIST_STRIP=	-p3

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.medias.ne.jp/~takam/bsd/NetBSD.html#spca561
COMMENT=	USB Cameras based SPCA5xx Utilities

WRKSRC=		${WRKDIR}/${DISTNAME}/drivers/usb
MAKE_ENV+=	NOGCCERROR=

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
