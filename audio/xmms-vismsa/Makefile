# $NetBSD: Makefile,v 1.10 2003/07/21 16:30:49 martti Exp $
#

DISTNAME=	vismsa-xmms-plugin-0.2
PKGNAME=	xmms-vismsa-0.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://a.godau.org/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://a.godau.org/
COMMENT=	Vis plugin similar to the Spectrum Analyser from Open Cubic Player

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
