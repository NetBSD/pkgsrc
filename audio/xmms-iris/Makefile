# $NetBSD: Makefile,v 1.2 2003/05/02 11:53:51 wiz Exp $
#

DISTNAME=	iris-0.11
PKGREVISION=	1
PKGNAME=	xmms-${DISTNAME}
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
