# $NetBSD: Makefile,v 1.11 2006/02/05 23:10:04 joerg Exp $
#

DISTNAME=	xlife-5.0
PKGREVISION=	5
CATEGORIES=	math games
MASTER_SITES=	http://www.tuxedo.org/~esr/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.tuxedo.org/~esr/software.html
COMMENT=	John Horton Conway's "Game of Life"

WRKSRC=		${WRKDIR}
USE_IMAKE=	yes

INSTALL_TARGET=	install

pre-build:
	${TOUCH} ${WRKSRC}/collect.man ${WRKSRC}/lifesearchdumb.man

post-install:
.for d in codd life misc wireworld
	${INSTALL_DATA_DIR} ${PREFIX}/share/xlife/${d}
	cd ${WRKSRC}/${d}; for l in *.l; do				\
		${INSTALL_DATA} $${l} ${PREFIX}/share/xlife/${d};	\
	done
.endfor

.include "../../mk/bsd.pkg.mk"
