# $NetBSD: Makefile,v 1.15 2004/03/08 19:40:36 jmmv Exp $
#

DISTNAME=	streamtuner-${DIST_VER}
PKGREVISION=	2
CATEGORIES=	audio www
MASTER_SITES=	http://savannah.nongnu.org/download/streamtuner/streamtuner.pkg/${DIST_VER}/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/streamtuner/
COMMENT=	Stream directory browser

DEPENDS+=		gnome2-dirs>=1.5:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	extras/streamtuner.pc.in

DIST_VER=		0.10.2

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
