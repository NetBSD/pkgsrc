# $NetBSD: Makefile,v 1.5 2001/08/16 04:40:28 zuntum Exp $
#

DISTNAME=	dscope-1.2
PKGNAME=	xmms-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual scope

USE_BUILDLINK_ONLY=	YES
USE_X11=	yes
USE_LIBTOOL=	yes
MAKE_ENV+=	GTK_CONFIG=${BUILDLINK_CONFIG_WRAPPER.gtk}
MAKE_ENV+=	XMMS_CONFIG=${BUILDLINK_CONFIG_WRAPPER.xmms}

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
