# $NetBSD: Makefile,v 1.9 2001/10/24 22:10:45 jlam Exp $
#

DISTNAME=	dscope-1.2
PKGNAME=	xmms-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual scope

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
