# $NetBSD: Makefile,v 1.8 2005/02/21 20:26:09 hubertf Exp $
#

DISTNAME=	dspectral-1.2
PKGNAME=	xmms-dspectral-1.2
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual spectral analyzer

USE_BUILDLINK3=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
