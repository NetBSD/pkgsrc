# $NetBSD: Makefile,v 1.1.1.1 2001/12/31 21:32:56 fredb Exp $
#

DISTNAME=	xlife-5.0
CATEGORIES=	math games
MASTER_SITES=	http://www.tuxedo.org/~esr/

MAINTAINER=	fredb@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/software.html
COMMENT=	John Horton Conway's "Game of Life"

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}

INSTALL_TARGET=	install

pre-build:
	${TOUCH} ${WRKSRC}/collect.man ${WRKSRC}/lifesearchdumb.man

post-install:
.for m in lifeconv lifesearch xlife
	${INSTALL_MAN} ${WRKSRC}/${m}.man ${PREFIX}/man/man1/${m}.1
	${INSTALL_MAN} ${WRKSRC}/${m}.0 ${PREFIX}/man/cat1/
.endfor
.for d in codd life misc wireworld
	${INSTALL_DATA_DIR} ${PREFIX}/share/xlife/${d}
	cd ${WRKSRC}/${d}; for l in *.l; do				\
		${INSTALL_DATA} $${l} ${PREFIX}/share/xlife/${d};	\
	done
.endfor

.include "../../mk/bsd.pkg.mk"
