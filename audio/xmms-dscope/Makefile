# $NetBSD: Makefile,v 1.15 2004/03/10 04:23:49 snj Exp $
#

DISTNAME=	dscope-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual scope

USE_BUILDLINK3=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
