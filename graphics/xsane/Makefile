# $NetBSD: Makefile,v 1.4 1999/08/04 18:31:53 rh Exp $
#

DISTNAME=	xsane-0.31
CATEGORIES=	graphics
MASTER_SITES=	http://www.wolfsburg.de/~rauch/sane/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.wolfsburg.de/~rauch/sane/sane-xsane.html

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	gtk+-1.2.2:../../x11/gtk
DEPENDS+=	sane-1.0.1:../../graphics/sane

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

CPPFLAGS+=	-I${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
