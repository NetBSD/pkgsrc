# $NetBSD: Makefile,v 1.6 2001/08/17 21:16:48 jlam Exp $
#

DISTNAME=	dspectogram-1.2
PKGNAME=	xmms-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual spectogram

USE_BUILDLINK_ONLY=	YES
USE_X11=	yes
USE_LIBTOOL=	yes

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
