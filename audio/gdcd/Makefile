# $NetBSD: Makefile,v 1.1.1.1 1999/09/03 22:15:46 rh Exp $
#

DISTNAME=	gdcd-0.0.2
CATEGORIES=	audio
MASTER_SITES=	http://cdcd.undergrid.net/gdcd/source_archive/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://cdcd.undergrid.net/gdcd/

DEPENDS+=	gtk+-1.2.4:../../x11/gtk
DEPENDS+=	imlib-1.9.4:../../graphics/imlib
DEPENDS+=	pth-1.1.5:../../devel/pth
DEPENDS+=	libcdaudio-0.99.1:../../audio/libcdaudio

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
LDFLAGS+=	-ltiff -ljpeg -lpng -lgif -lz -lm

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${PREFIX}/include"

.include "../../mk/bsd.pkg.mk"
