# $NetBSD: Makefile,v 1.18 2005/04/11 21:44:58 tv Exp $
#

DISTNAME=	dscope-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual scope

USE_X11=		YES
USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
