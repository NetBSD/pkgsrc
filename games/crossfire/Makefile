# $NetBSD: Makefile,v 1.6 2000/05/25 09:07:31 wiz Exp $
#

DISTNAME=	crossfire-0.94.2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/crossfire/
DISTFILES=	${CF_SRC} ${CF_MAPS} ${CF_SOUND}

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.fak14.uni-muenchen.de/~h729ihqu/games/crossfire.html

DEPENDS+=	rplay>=3.2.0:../../audio/rplay
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

# for rplay
MAKE_ENV+=	LOCALBASE=${LOCALBASE}

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
	@cd ${WRKSRC}/utils && \
		${MV} mktable.script mktable.script.orig && \
		${SED} "s@/usr/local@${LOCALBASE}@" mktable.script.orig > \
			mktable.script
	@cd ${WRKSRC}/utils && \
		${MV} mapconv.script mapconv.script.orig && \
		${SED} "s@/usr/local@${LOCALBASE}@" mapconv.script.orig > \
			mapconv.script

post-install:
	cd ${X11BASE}/lib/crossfire && \
	    ${GZCAT} ${DISTDIR}/${CF_MAPS} | ${GTAR} xmf -
	cd ${X11BASE}/lib/crossfire && \
	    ${GZCAT} ${DISTDIR}/${CF_SOUND} | ${GTAR} xmf -
	@${FIND} ${X11BASE}/lib/crossfire/sounds -name \*.au -type f \
		> ${WRKDIR}/.RPLAY
	@${CAT} ${WRKDIR}/.RPLAY >> ${LOCALBASE}/etc/rplay.conf
	@${CAT} ${WRKDIR}/.RPLAY >> ${DEINSTALL_FILE}
	@${CAT} ${WRKDIR}/.RPLAY >> ${INSTALL_FILE}
	@${ECHO} "EOF" >> ${INSTALL_FILE}
	@${CHOWN} root:games ${X11BASE}/bin/crossfire
	@${CHMOD} 2755 ${X11BASE}/bin/crossfire
	@${CHOWN} -R root:games ${X11BASE}/lib/crossfire
	@${CHMOD} 775 ${X11BASE}/lib/crossfire/players
	@${CHMOD} 775 ${X11BASE}/lib/crossfire/unique-items
	@${CHMOD} 775 ${X11BASE}/lib/crossfire
	@${CHMOD} 664 ${X11BASE}/lib/crossfire/highscore

pre-clean:
	@${RM} -f ${DEINSTALL_FILE} ${INSTALL_FILE} ${WRKDIR}/.RPLAY

.include "../../mk/bsd.pkg.mk"
