# $NetBSD: Makefile,v 1.8 2001/10/23 13:14:44 jlam Exp $
#

DISTNAME=	dspectogram-1.2
PKGNAME=	xmms-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual spectogram

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../mk/x11.buildlink.mk"
.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
