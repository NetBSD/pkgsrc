# $NetBSD: Makefile,v 1.5 2001/08/16 03:34:22 zuntum Exp $
#

DISTNAME=	dflowers_v1.0
PKGNAME=	xmms-dflowers-1.0
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual flower scope

USE_X11=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
MAKE_ENV+=	GTK_CONFIG=${BUILDLINK_CONFIG_WRAPPER.gtk}

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
