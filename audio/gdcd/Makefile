# $NetBSD: Makefile,v 1.2 1999/10/09 16:51:09 jlam Exp $
#

DISTNAME=	gdcd-0.0.2
CATEGORIES=	audio
MASTER_SITES=	http://cdcd.undergrid.net/gdcd/source_archive/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://cdcd.undergrid.net/gdcd/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-1.9.4:../../graphics/imlib
DEPENDS+=	pth-1.1.6:../../devel/pth
DEPENDS+=	libcdaudio-0.99.1:../../audio/libcdaudio

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

# for pth and libcdaudio
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
