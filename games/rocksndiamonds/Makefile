# $NetBSD: Makefile,v 1.9 2002/10/23 13:24:53 heinz Exp $
#

DISTNAME=		rocksndiamonds-2.1.1
PKGREVISION=		# empty
CATEGORIES=		games x11
MASTER_SITES=		http://www.artsoft.org/RELEASES/unix/rocksndiamonds/

MAINTAINER=		heinz-rnd@netbsd.org
HOMEPAGE=		http://www.artsoft.org/rocksndiamonds/
COMMENT=		Game like Boulderdash, Emerald Mine, or Sokoban with lots of levels

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_X11=		YES

PLIST_SUBST+=		SCORE_PATH=${SCORE_PATH}
PLIST_SUBST+=		ROCK_INSTALL_DIR="${INSTALL} -d -o games -g games -m 775"

.if ( ${MACHINE} == "i386" || ${MACHINE} == "prep" || ${MACHINE} == "cats" || \
      ${MACHINE} == "shark" )
MAKE_ENV+=HAVE_JOYSTICK=1
.endif

SCORE_PATH=		/var/games/rocksndiamonds

pre-configure:
	@${SED} -e "s,@SCORE_PATH@,${SCORE_PATH},g" \
	        ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.fixed && \
	  ${MV} ${WRKSRC}/Makefile.fixed ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} -o games -g games -m 2755 \
		${WRKSRC}/rocksndiamonds ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/rocksndiamonds.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/rocksndiamonds
	cd ${WRKSRC} && ${PAX} -r -w sounds graphics levels music \
		${PREFIX}/share/rocksndiamonds/
	${CHOWN} -R games:games ${PREFIX}/share/rocksndiamonds
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
	${CHOWN} -R games:games ${SCORE_PATH}

.include "../../mk/bsd.pkg.mk"
