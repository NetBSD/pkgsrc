# $NetBSD: Makefile,v 1.4 2001/08/16 03:34:22 zuntum Exp $
#

DISTNAME=	dspectral-1.2
PKGNAME=	xmms-dspectral-1.2
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual spectral analyzer

USE_X11=	yes
USE_LIBTOOL=	yes
MAKE_ENV+=	GTK_CONFIG=${BUILDLINK_CONFIG_WRAPPER.gtk}

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
