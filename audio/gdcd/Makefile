# $NetBSD: Makefile,v 1.7 2001/02/16 13:30:41 wiz Exp $
#

DISTNAME=	gdcd-0.0.2
CATEGORIES=	audio
MASTER_SITES=	http://cdcd.undergrid.net/gdcd/source_archive/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://cdcd.undergrid.net/gdcd/
COMMENT=	CD player for the X Window System using the GIMP Tool Kit (GTK)

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	pth>=1.2.0:../../devel/pth
DEPENDS+=	libcdaudio>=0.99.1:../../audio/libcdaudio

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

# for pth and libcdaudio
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
