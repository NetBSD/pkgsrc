# $NetBSD: Makefile,v 1.8 2006/10/22 21:16:08 rillig Exp $
#

DISTNAME=	snx101util-0.2
PKGREVISION=	3
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.medias.ne.jp/~takam/bsd/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.medias.ne.jp/~takam/bsd/NetBSD.html#sonix
COMMENT=	USB Webcam based sonix SN9C101 chip Utility Programs

MAKE_ENV+=	NOGCCERROR=
MAKE_ENV+=	${BSD_MAKE_ENV}

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
