# $NetBSD: Makefile,v 1.6 2003/05/02 11:53:54 wiz Exp $
#

DISTNAME=	vismsa-xmms-plugin-0.2
PKGREVISION=	1
PKGNAME=	xmms-vismsa-0.2
CATEGORIES=	audio
MASTER_SITES=	http://a.godau.org/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://a.godau.org/
COMMENT=	vis plugin similar to the Spectrum Analyser from Open Cubic Player

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
