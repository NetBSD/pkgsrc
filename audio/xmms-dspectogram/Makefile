# $NetBSD: Makefile,v 1.2 2001/08/16 03:10:43 hubertf Exp $
#

DISTNAME=	dspectogram-1.2
PKGNAME=	xmms-dspectogram-1.2
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual spectogram

DEPENDS+=	xmms>=1.2.5:../../audio/xmms

USE_X11=	yes
USE_LIBTOOL=	yes

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
