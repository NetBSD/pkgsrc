# $NetBSD: Makefile,v 1.18 2008/03/02 06:10:32 jlam Exp $
#

DISTNAME=	gnome-audio-2.0.0
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-audio/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Set of audio files for GNOME

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_DIRS+=	xdg-1.1

do-install:
	cd ${WRKSRC}/sounds && for f in *.wav */*.wav; do \
		dst=`${DIRNAME} $$f`; \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/sounds/$$dst; \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/sounds/$$f; \
	done
	${RM} -f ${DESTDIR}${PREFIX}/share/sounds/login.wav
	${RM} -f ${DESTDIR}${PREFIX}/share/sounds/logout.wav
	${LN} -fs startup3.wav ${DESTDIR}${PREFIX}/share/sounds/login.wav
	${LN} -fs shutdown1.wav ${DESTDIR}${PREFIX}/share/sounds/logout.wav

.include "../../mk/bsd.pkg.mk"
