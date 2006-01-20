# $NetBSD: Makefile,v 1.28 2006/01/20 22:37:05 adam Exp $

DISTNAME=	rocksndiamonds-3.1.2
CATEGORIES=	games x11
MASTER_SITES=	http://www.artsoft.org/RELEASES/unix/rocksndiamonds/

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://www.artsoft.org/rocksndiamonds/
COMMENT=	Game like Boulder Dash, Emerald Mine, or Sokoban (X11 build)

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	${PKGMANDIR}/man6

PLIST_SRC=	${WRKDIR}/PLIST PLIST
PLIST_SUBST+=	SCORE_PATH=${SCORE_PATH:Q}
PLIST_SUBST+=	ROCK_INSTALL_DIR="${INSTALL} -d -o ${RND_USER} -g ${RND_GROUP} -m 775"

PKG_GROUPS=	${RND_GROUP}
PKG_USERS=	${RND_USER}:${RND_GROUP}

RND_USER=	games
RND_GROUP=	games

.if ( ${MACHINE} == "i386" || ${MACHINE} == "prep" || ${MACHINE} == "cats" || \
      ${MACHINE} == "shark" )
MAKE_ENV+=	HAVE_JOYSTICK=1
.endif

.include "options.mk"

SCORE_PATH=	${VARBASE}/games/rocksndiamonds

pre-configure:
	@${SED} -e "s,@SCORE_PATH@,${SCORE_PATH},g" \
		${WRKSRC}/Makefile > ${WRKSRC}/Makefile.fixed && \
	  ${MV} ${WRKSRC}/Makefile.fixed ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} -o ${RND_USER} -g ${RND_GROUP} -m 2755 \
		${WRKSRC}/rocksndiamonds ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/rocksndiamonds.1 \
		${PREFIX}/${PKGMANDIR}/man6/rocksndiamonds.6
	${INSTALL_DATA_DIR} ${PREFIX}/share/rocksndiamonds
	cd ${WRKSRC} && ${PAX} -rw sounds graphics levels music \
		${PREFIX}/share/rocksndiamonds/
	${CHOWN} -R ${RND_USER}:${RND_GROUP} ${PREFIX}/share/rocksndiamonds
	${CHMOD} -R a-w ${PREFIX}/share/rocksndiamonds
	${INSTALL_DATA_DIR} ${SCORE_PATH}/scores
	${CHMOD} 755 ${SCORE_PATH}
	${CHMOD} 775 ${SCORE_PATH}/scores
	# extract basenames of level subdirectories, levelinfo.conf is a file
	LEVELDIRS=`${LS} -d ${WRKSRC}/levels/*/* | \
		${SED} -e 's@^.*/\([^/]*\)$$@\1@' -e '/levelinfo\.conf/d'` && \
	  for directory in $${LEVELDIRS}; do \
	    ${INSTALL_DATA_DIR} ${SCORE_PATH}/scores/$${directory}; \
	    ${CHMOD} 775 ${SCORE_PATH}/scores/$${directory}; \
	  done
	${CHOWN} -R ${RND_USER}:${RND_GROUP} ${SCORE_PATH}
	# auto-generated PLIST
	${RM} -f ${WRKDIR}/PLIST
.for levdir in Classic_Games Tutorials
	cd ${PREFIX} && \
	${FIND} share/rocksndiamonds/levels/${levdir} -type f -print >>${WRKDIR}/PLIST
.endfor
.for directory in graphics music sounds
	cd ${PREFIX} && \
	${FIND} share/rocksndiamonds/${directory} -type f -print >>${WRKDIR}/PLIST
.endfor

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
