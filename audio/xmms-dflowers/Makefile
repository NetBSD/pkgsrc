# $NetBSD: Makefile,v 1.2 2001/08/16 01:41:31 hubertf Exp $
#

DISTNAME=	dflowers_v1.0
PKGNAME=	xmms-dflowers-1.0
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual flower scope

DEPENDS+=	xmms>=1.2.5:../../audio/xmms

USE_X11=	yes
USE_LIBTOOL=	yes

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
