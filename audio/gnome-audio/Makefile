# $NetBSD: Makefile,v 1.16 2006/02/05 23:08:08 joerg Exp $
#

DISTNAME=	gnome-audio-2.0.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-audio/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of audio files for GNOME

NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_DIRS+=	xdg-1.1

.include "../../mk/x11.buildlink3.mk"

do-install:
	cd ${WRKSRC}/sounds && for f in *.wav */*.wav; do \
		dst=`${DIRNAME} $$f`; \
		${INSTALL_DATA_DIR} ${PREFIX}/share/sounds/$$dst; \
		${INSTALL_DATA} $$f ${PREFIX}/share/sounds/$$f; \
	done
	${RM} -f ${PREFIX}/share/sounds/login.wav
	${RM} -f ${PREFIX}/share/sounds/logout.wav
	${LN} -fs startup3.wav ${PREFIX}/share/sounds/login.wav
	${LN} -fs shutdown1.wav ${PREFIX}/share/sounds/logout.wav

.include "../../mk/bsd.pkg.mk"
