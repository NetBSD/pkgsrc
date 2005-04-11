# $NetBSD: Makefile,v 1.14 2005/04/11 21:45:00 tv Exp $
#

DISTNAME=	vismsa-xmms-plugin-0.2
PKGNAME=	xmms-vismsa-0.2
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://a.godau.org/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://a.godau.org/
COMMENT=	Vis plugin similar to the Spectrum Analyser from Open Cubic Player

USE_X11=		YES
USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
