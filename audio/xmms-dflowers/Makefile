# $NetBSD: Makefile,v 1.7 2001/08/17 21:16:47 jlam Exp $
#

DISTNAME=	dflowers-1.2
PKGNAME=	xmms-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual flower scope

USE_BULIDLINK_ONLY=	YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
