# $NetBSD: Makefile,v 1.6 2001/08/16 04:30:11 zuntum Exp $
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

MAKE_ENV+=	GTK_CONFIG=${BUILDLINK_CONFIG_WRAPPER.gtk}
MAKE_ENV+=	XMMS_CONFIG=${BUILDLINK_CONFIG_WRAPPER.xmms}

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
