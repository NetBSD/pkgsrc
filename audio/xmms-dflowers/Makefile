# $NetBSD: Makefile,v 1.14 2003/05/05 19:05:06 jmmv Exp $
#

DISTNAME=	dflowers-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual flower scope

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
