# $NetBSD: Makefile,v 1.7 2002/10/19 10:54:42 rh Exp $
#

DISTNAME=	gnome-audio-1.4.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-audio/1.4/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of audio files for GNOME

NO_CONFIGURE=	YES
USE_X11BASE=	YES
MAKE_ENV+=	prefix="${PREFIX}"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sounds
	${INSTALL_DATA_DIR} ${PREFIX}/share/sounds/panel
	${INSTALL_DATA_DIR} ${PREFIX}/share/sounds/gtk-events
.for file in card_shuffle phone shutdown1 startup3 warning email error \
	     generic info panel/slide gtk-events/activate gtk-events/clicked \
	     gtk-events/toggled
	${INSTALL_DATA} ${WRKSRC}/sounds/${file}.wav \
	                ${PREFIX}/share/sounds/${file}.wav
.endfor
	${LN} -fs startup3.wav ${PREFIX}/share/sounds/login.wav
	${LN} -fs shutdown1.wav ${PREFIX}/share/sounds/logout.wav

.include "../../mk/bsd.pkg.mk"
