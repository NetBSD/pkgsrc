# $NetBSD: Makefile,v 1.20 2006/01/19 18:14:49 joerg Exp $
#

DISTNAME=		xblast-2.6.beta-sound
PKGNAME=		xblast-2.6b
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.ikp.uni-koeln.de/~vogel/archive/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.ikp.uni-koeln.de/~vogel/xblast/xblast.html
COMMENT=		2-6 player kill the other guy with bombs game. A real blast!

DEPENDS+=		tk>=8.3.2:../../x11/tk

WRKSRC=			${WRKDIR}/XBlast-2.6.beta
USE_IMAKE=		yes

post-patch:
	cd ${WRKSRC} ; ${SED} '/file_appl_def/s@/usr/lib/X11@'${PREFIX}'/lib/X11@' defaults.h >xx ; ${MV} xx defaults.h
	${TOUCH} ${WRKSRC}/xbsndsrv.man
	for dir in bitmap image; do \
		for sub in block explosion misc score sprite; do \
			${MV} ${WRKSRC}/$$dir/$$sub/Imakefile ${WRKSRC}/$$dir/$$sub/foo; \
			${SED} -e 's|XBLASTDIR=.*/xblast|XBLASTDIR=${PREFIX}/share/xblast|' <${WRKSRC}/$$dir/$$sub/foo>${WRKSRC}/$$dir/$$sub/Imakefile; \
			${RM} ${WRKSRC}/$$dir/$$sub/foo; \
		done; \
	done

post-build:
	cd ${WRKSRC}/tkXBlast && ${MAKE_ENV} ${MAKE}

post-install:
	${RM} ${PREFIX}/${IMAKE_MAN_DIR}/xbsndsrv.${IMAKE_MAN_SUFFIX}

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
