# $NetBSD: Makefile,v 1.16 2004/03/10 04:24:58 snj Exp $
#

DISTNAME=	dspectogram-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.shell.linux.se/bm/index.php?page=xmmsplugin
COMMENT=	XMMS plugin for dual spectogram

USE_BUILDLINK3=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
