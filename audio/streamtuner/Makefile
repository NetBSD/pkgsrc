# $NetBSD: Makefile,v 1.8 2003/09/18 21:57:06 xtraeme Exp $
#

DISTNAME=	streamtuner-0.10.1
CATEGORIES=	audio www
MASTER_SITES=	http://savannah.nongnu.org/download/streamtuner/streamtuner.pkg/0.10.1/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/streamtuner/
COMMENT=	Stream directory browser

DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/extras/streamtuner.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
