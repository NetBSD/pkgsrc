# $NetBSD: Makefile,v 1.10 2005/02/21 20:26:09 hubertf Exp $
#

DISTNAME=	iris-0.11
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	xmms audio
MASTER_SITES=	http://cdelfosse.free.fr/xmms-iris/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://cdelfosse.free.fr/xmms-iris/
COMMENT=	OpenGL Spectrum Analyzer with theme engine and fullscreen modes

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES

.include "../../mk/bsd.prefs.mk"

# Needs libXxf86vm.so which isn't provided on NetBSD currently.
.if !exists(${X11BASE}/lib/libXxf86vm.so)
PKG_FAIL_REASON=	"${PKGNAME} requires libXxf86vm.so"
.endif

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
