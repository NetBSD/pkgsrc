# $NetBSD: Makefile,v 1.17 2004/03/30 22:21:31 xtraeme Exp $
#

DISTNAME=	streamtuner-0.12.1
CATEGORIES=	audio www
MASTER_SITES=	http://savannah.nongnu.org/download/streamtuner/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/streamtuner/
COMMENT=	Stream directory browser

DEPENDS+=		gnome2-dirs>=1.5:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	extras/streamtuner.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
