# $NetBSD: Makefile,v 1.1.1.1 2003/02/15 00:44:42 hubertf Exp $
#

DISTNAME=	dspectral-1.2
PKGNAME=	xmms-dspectral-1.2
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual spectral analyzer

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
