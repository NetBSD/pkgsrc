# $NetBSD: Makefile,v 1.7 2003/08/28 20:05:14 xtraeme Exp $
#

DISTNAME=	streamtuner-0.10.0
CATEGORIES=	audio www
MASTER_SITES=	http://savannah.nongnu.org/download/streamtuner/streamtuner.pkg/0.10.0/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/streamtuner/
COMMENT=	Stream directory browser

DEPENDS+=	gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/extras/streamtuner.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../www/curl/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
