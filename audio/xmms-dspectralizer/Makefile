# $NetBSD: Makefile,v 1.3 2001/08/16 03:20:46 hubertf Exp $
#

DISTNAME=	dspectral-1.2
PKGNAME=	xmms-dspectral-1.2
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual spectral analyzer

DEPENDS+=	xmms>=1.2.5:../../audio/xmms

USE_X11=	yes
USE_LIBTOOL=	yes
MAKE_ENV+=	GTK_CONFIG=${BUILDLINK_CONFIG_WRAPPER.gtk}

pre-build:
		cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
