# $NetBSD: Makefile,v 1.3 2003/05/05 19:05:07 jmmv Exp $
#

DISTNAME=	iris-0.11
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	xmms audio
MASTER_SITES=	http://cdelfosse.free.fr/xmms-iris/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://cdelfosse.free.fr/xmms-iris/
COMMENT=	OpenGL Spectrum Analyzer with theme engine and fullscreen modes

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
