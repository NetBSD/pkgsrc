# $NetBSD: Makefile,v 1.3 1998/09/17 14:03:49 agc Exp $
#

DISTNAME=	crossfire-0.94.2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/crossfire/
DISTFILES=	${CF_SRC} ${CF_MAPS} ${CF_SOUND}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.fak14.uni-muenchen.de/~h729ihqu/games/crossfire.html

DEPENDS+=	rplay-3.2.0b6:../../audio/rplay
DEPENDS+=	xpm-3.4k:../../graphics/xpm

EXTRACT_ONLY=	${CF_SRC}

CF_SRC=		crossfire-0.94.2.tar.gz
CF_MAPS=	crossfire-0.94.2.maps.tar.gz
CF_SOUND=	crossfire-0.92.7.sounds.tar.gz

USE_IMAKE=	yes
USE_PERL5=	yes
SCRIPTS_ENV+=	${SCRIPTSDIR}

INSTALL_FILE=	${WRKDIR}/.INSTALL
DEINSTALL_FILE=	${WRKDIR}/.DEINSTALL

post-patch:
	@${MV} ${WRKSRC}/config/crosssite.def \
		${WRKSRC}/config/crosssite.def-orig
	@${SED} -e 's|@X11BASE@|${X11BASE}|g' \
		-e 's|@LOCALBASE@|${LOCALBASE}|g' \
		${WRKSRC}/config/crosssite.def-orig \
		> ${WRKSRC}/config/crosssite.def
	@${MV} ${WRKSRC}/lib/sounds ${WRKSRC}/lib/sound_list
	@${SED} -e 's|XXXLOCALBASEXXX|${LOCALBASE}|' \
		-e 's|XXXDBXXX|${PKG_DBDIR}/${DISTNAME}|' \
		${PKGDIR}/deinstall > ${DEINSTALL_FILE}
	@${SED} -e 's|XXXLOCALBASEXXX|${LOCALBASE}|' \
		-e 's|XXXX11BASEXXX|${X11BASE}|' \
		${PKGDIR}/install > ${INSTALL_FILE}

post-install:
	${EXTRACT_CMD} -xzmf ${DISTDIR}/${CF_MAPS} -C ${X11BASE}/lib/crossfire
	${EXTRACT_CMD} -xzmf ${DISTDIR}/${CF_SOUND} -C ${X11BASE}/lib/crossfire
	@/usr/bin/find ${X11BASE}/lib/crossfire/sounds -name \*.au -type f \
		> ${WRKDIR}/.RPLAY
	@${CAT} ${WRKDIR}/.RPLAY >> ${LOCALBASE}/etc/rplay.conf
	@${CAT} ${WRKDIR}/.RPLAY >> ${DEINSTALL_FILE}
	@${CAT} ${WRKDIR}/.RPLAY >> ${INSTALL_FILE}
	@${ECHO} "EOF" >> ${INSTALL_FILE}
	@chown root:games ${X11BASE}/bin/crossfire
	@chmod 2755 ${X11BASE}/bin/crossfire
	@chown -R root:games ${X11BASE}/lib/crossfire
	@chmod 775 ${X11BASE}/lib/crossfire/players
	@chmod 775 ${X11BASE}/lib/crossfire
	@chmod 664 ${X11BASE}/lib/crossfire/highscore

pre-clean:
	@${RM} -f ${DEINSTALL_FILE} ${INSTALL_FILE} ${WRKDIR}/.RPLAY

.include "../../mk/bsd.pkg.mk"
