# $NetBSD: Makefile,v 1.3 2001/10/23 13:14:45 jlam Exp $
#

DISTNAME=	vismsa-xmms-plugin-0.2
PKGNAME=	xmms-vismsa-0.2
CATEGORIES=	audio
MASTER_SITES=	http://a.godau.org/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://a.godau.org/
COMMENT=	vis plugin similar to the Spectrum Analyser from Open Cubic Player

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../mk/x11.buildlink.mk"
.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
