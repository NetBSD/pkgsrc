# $NetBSD: Makefile,v 1.2 1998/09/14 06:37:01 garbled Exp $
#

DISTNAME=	imlib-1.7
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.labs.redhat.com/imlib/

DEPENDS+=	gtk+-1.1.1:../../x11/gtk
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	giflib-3.0:../../graphics/giflib

USE_X11=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}
CONFIGURE_ENV+=		CPPFLAGS='-I${LOCALBASE}/include -I${LOCALBASE}/include/giflib'

WRKSRC=		${WRKDIR}/imlib

.include "../../mk/bsd.pkg.mk"
