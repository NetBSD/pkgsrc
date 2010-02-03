# $NetBSD: Makefile,v 1.11 2010/02/03 22:15:27 joerg Exp $
#

DISTNAME=	spca5xx-20060402
PKGNAME=	spcaview-0.6b
#PKGREVISION=	1
PKGREVISION=	2
CATEGORIES=	graphics x11
MASTER_SITES=	http://mxhaard.free.fr/spca50x/Download/oldrelease/

PATCH_SITES=	http://www.medias.ne.jp/~takam/bsd/
PATCHFILES= 	spca5xx-bsd-0.6b.patch.gz
PATCH_DIST_STRIP=	-p3

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.medias.ne.jp/~takam/bsd/NetBSD.html#spca561
COMMENT=	USB Cameras based SPCA5xx Utilities

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/drivers/usb
MAKE_ENV+=	NOGCCERROR=
MAKE_ENV+=	${BSD_MAKE_ENV}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
