# $NetBSD: Makefile,v 1.15 2011/02/19 09:02:07 markd Exp $
#

DISTNAME=	snx101util-0.2
PKGREVISION=	8
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.medias.ne.jp/~takam/bsd/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.medias.ne.jp/~takam/bsd/NetBSD.html#sonix
COMMENT=	USB Webcam based sonix SN9C101 chip Utility Programs

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	NOGCCERROR=
MAKE_ENV+=	${BSD_MAKE_ENV}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../graphics/imlib-gtk/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
