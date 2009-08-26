# $NetBSD: Makefile,v 1.10 2009/08/26 19:57:51 sno Exp $
#

DISTNAME=	snx101util-0.2
PKGREVISION=	4
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.medias.ne.jp/~takam/bsd/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.medias.ne.jp/~takam/bsd/NetBSD.html#sonix
COMMENT=	USB Webcam based sonix SN9C101 chip Utility Programs

MAKE_ENV+=	NOGCCERROR=
MAKE_ENV+=	${BSD_MAKE_ENV}

INSTALLATION_DIRS=	${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
