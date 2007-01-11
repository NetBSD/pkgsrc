# $NetBSD: Makefile,v 1.16 2007/01/11 11:47:09 joerg Exp $
#

DISTNAME=	iris-0.11
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	xmms audio
MASTER_SITES=	http://cdelfosse.free.fr/xmms-iris/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cdelfosse.free.fr/xmms-iris/
COMMENT=	OpenGL Spectrum Analyzer with theme engine and fullscreen modes

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

.include "../../audio/xmms/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
