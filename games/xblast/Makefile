# $NetBSD: Makefile,v 1.13 2001/05/05 19:51:14 jlam Exp $
#

DISTNAME=		xblast-2.6.beta-sound
PKGNAME=		xblast-2.6b
WRKSRC=			${WRKDIR}/XBlast-2.2
CATEGORIES=		games x11
MASTER_SITES=		http://www.ikp.uni-koeln.de/~vogel/archive/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.ikp.uni-koeln.de/~vogel/xblast/xblast.html
COMMENT=		2-6 player kill the other guy with bombs game. A real blast!

DEPENDS+=		tk>=8.3.2:../../x11/tk

USE_IMAKE=		yes

WRKSRC=			${WRKDIR}/XBlast-2.6.beta

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
	${RM} ${PREFIX}/man/cat1/xbsndsrv.0

.include "../../mk/bsd.pkg.mk"
