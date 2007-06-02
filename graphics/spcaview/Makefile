# $NetBSD: Makefile,v 1.8 2007/06/02 12:47:51 hamajima Exp $
#

DISTNAME=	spca5xx-20060402
PKGNAME=	spcaview-0.6b
#PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	http://mxhaard.free.fr/spca50x/Download/oldrelease/

PATCH_SITES=	http://www.medias.ne.jp/~takam/bsd/
PATCHFILES= 	spca5xx-bsd-0.6b.patch.gz
PATCH_DIST_STRIP=	-p3

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.medias.ne.jp/~takam/bsd/NetBSD.html#spca561
COMMENT=	USB Cameras based SPCA5xx Utilities

WRKSRC=		${WRKDIR}/${DISTNAME}/drivers/usb
MAKE_ENV+=	NOGCCERROR=
MAKE_ENV+=	${BSD_MAKE_ENV}

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
