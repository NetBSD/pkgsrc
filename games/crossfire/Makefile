# $NetBSD: Makefile,v 1.1 1998/07/25 17:40:41 frueauf Exp $
#

DISTNAME=	crossfire-0.94.2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/crossfire/
DISTFILES=	${CF_SRC} ${CF_MAPS} ${CF_SOUND}

MAINTAINER=	root@garbled.net

DEPENDS+=	rplay-3.2.0b6:../../audio/rplay
DEPENDS+=	xpm-3.4k:../../graphics/xpm

EXTRACT_ONLY=	${CF_SRC}

CF_SRC=		crossfire-0.94.2.tar.gz
CF_MAPS=	crossfire-0.94.2.maps.tar.gz
CF_SOUND=	crossfire-0.92.7.sounds.tar.gz

USE_IMAKE=	yes
USE_PERL5=	yes
SCRIPTS_ENV+=	${SCRIPTSDIR}

post-patch:
	@${MV} ${WRKSRC}/config/crosssite.def \
		${WRKSRC}/config/crosssite.def-orig
	@${SED} -e 's|@X11BASE@|${X11BASE}|g' \
		-e 's|@LOCALBASE@|${LOCALBASE}|g' \
		< ${WRKSRC}/config/crosssite.def-orig \
		> ${WRKSRC}/config/crosssite.def
	@${MV} ${WRKSRC}/lib/sounds ${WRKSRC}/lib/sound_list
	@${SED} -e 's|XXXLOCALBASEXXX|${LOCALBASE}|' \
		-e 's|XXXDBXXX|${PKG_DBDIR}/${DISTNAME}|' \
		< ${PKGDIR}/deinstall >${PKGDIR}/DEINSTALL
	@${SED} -e 's|XXXLOCALBASEXXX|${LOCALBASE}|' \
		-e 's|XXXX11BASEXXX|${X11BASE}|' \
		< ${PKGDIR}/install >${PKGDIR}/INSTALL

post-install:
	${EXTRACT_CMD} -xzmf ${DISTDIR}/${CF_MAPS} -C ${X11BASE}/lib/crossfire
	${EXTRACT_CMD} -xzmf ${DISTDIR}/${CF_SOUND} -C ${X11BASE}/lib/crossfire
	@/usr/bin/find ${X11BASE}/lib/crossfire/sounds -name \*.au -type f \
		> ${PKGDIR}/RPLAY
	@${CAT} ${PKGDIR}/RPLAY >> ${LOCALBASE}/etc/rplay.conf
	@${CAT} ${PKGDIR}/RPLAY >> ${PKGDIR}/DEINSTALL
	@${CAT} ${PKGDIR}/RPLAY >> ${PKGDIR}/INSTALL
	@${ECHO} "EOF" >> ${PKGDIR}/INSTALL
	@chown root:games ${X11BASE}/bin/crossfire
	@chmod 2755 ${X11BASE}/bin/crossfire
	@chown -R root:games ${X11BASE}/lib/crossfire
	@chmod 775 ${X11BASE}/lib/crossfire/players
	@chmod 775 ${X11BASE}/lib/crossfire
	@chmod 664 ${X11BASE}/lib/crossfire/highscore

pre-clean:
	@${RM} -f ${PKGDIR}/DEINSTALL ${PKGDIR}/INSTALL ${PKGDIR}/RPLAY

.include "../../mk/bsd.pkg.mk"
