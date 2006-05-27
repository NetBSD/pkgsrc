# $NetBSD: Makefile,v 1.7 2006/05/27 02:44:21 hamajima Exp $
#

DISTNAME=	snx101util-0.2
PKGREVISION=	3
CATEGORIES=	graphics x11
MASTER_SITES=	http://www.medias.ne.jp/~takam/bsd/

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www.medias.ne.jp/~takam/bsd/NetBSD.html#sonix
COMMENT=	USB Webcam based sonix SN9C101 chip Utility Programs

MAKE_ENV+=	NOGCCERROR=

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
