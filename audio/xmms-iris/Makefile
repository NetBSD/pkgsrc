# $NetBSD: Makefile,v 1.6 2003/07/17 21:24:05 grant Exp $
#

DISTNAME=	iris-0.11
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	xmms audio
MASTER_SITES=	http://cdelfosse.free.fr/xmms-iris/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://cdelfosse.free.fr/xmms-iris/
COMMENT=	OpenGL Spectrum Analyzer with theme engine and fullscreen modes

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=	YES

# Needs libXxf86vm.so which isn't provided on NetBSD currently.
NOT_FOR_PLATFORM=NetBSD-*

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
