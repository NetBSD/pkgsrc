# $NetBSD: Makefile,v 1.1.1.1 2001/08/16 02:24:09 hubertf Exp $
#

DISTNAME=	dscope-1.2
PKGNAME=	xmms-dscope-1.2
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual scope

DEPENDS+=	xmms>=1.2.5:../../audio/xmms

USE_X11=	yes
USE_LIBTOOL=	yes

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
