# $NetBSD: Makefile,v 1.6 2004/07/22 17:11:35 drochner Exp $
#

DISTNAME=	xlife-5.0
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	math games
MASTER_SITES=	http://www.tuxedo.org/~esr/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.tuxedo.org/~esr/software.html
COMMENT=	John Horton Conway's "Game of Life"

WRKSRC=		${WRKDIR}
USE_IMAKE=	yes
USE_BUILDLINK3=	yes

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
