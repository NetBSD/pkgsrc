# $NetBSD: Makefile,v 1.3 2000/01/02 18:02:40 tron Exp $
#

DISTNAME=	gnome-audio-1.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/releases/gnome-1.0.53/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

NO_CONFIGURE=	YES
USE_X11BASE=	YES
MAKE_ENV+=	prefix="${PREFIX}"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sounds
	${INSTALL_DATA_DIR} ${PREFIX}/share/sounds/panel
	${INSTALL_DATA_DIR} ${PREFIX}/share/sounds/gtk-events
.for file in card_shuffle phone shutdown1 startup1 startup2 startup3 panel/slide \
	     gtk-events/activate gtk-events/clicked gtk-events/toggled
	${INSTALL_DATA} ${WRKSRC}/sounds/${file}.wav \
	                ${PREFIX}/share/sounds/${file}.wav
.endfor
	${LN} -fs startup3.wav ${PREFIX}/share/sounds/login.wav
	${LN} -fs shutdown1.wav ${PREFIX}/share/sounds/logout.wav

.include "../../mk/bsd.pkg.mk"
