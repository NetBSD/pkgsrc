# $NetBSD: Makefile,v 1.14 2003/07/17 21:24:00 grant Exp $
#

DISTNAME=	dspectogram-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual spectogram

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
