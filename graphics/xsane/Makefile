# $NetBSD: Makefile,v 1.1.1.1 1999/04/06 05:57:31 rh Exp $
#

DISTNAME=	xsane-0.19
CATEGORIES=	graphics
MASTER_SITES=	http://www.wolfsburg.de/~rauch/sane/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.wolfsburg.de/~rauch/sane/sane-xsane.html

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	gtk10-1.0.6:../../x11/gtk10
DEPENDS+=	sane-1.00:../../graphics/sane

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES
CONFIGURE_ENV+=	GTK_CONFIG="${X11BASE}/bin/gtk10-config"

CPPFLAGS+=	-I${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
