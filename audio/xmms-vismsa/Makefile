# $NetBSD: Makefile,v 1.11 2004/03/12 04:37:38 snj Exp $
#

DISTNAME=	vismsa-xmms-plugin-0.2
PKGNAME=	xmms-vismsa-0.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://a.godau.org/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://a.godau.org/
COMMENT=	Vis plugin similar to the Spectrum Analyser from Open Cubic Player

USE_BUILDLINK3=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
