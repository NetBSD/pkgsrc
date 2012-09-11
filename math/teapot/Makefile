# $NetBSD: Makefile,v 1.2 2012/09/11 23:04:34 asau Exp $
#

DISTNAME=	teapot-1.09
CATEGORIES=	math
MASTER_SITES=	http://www.moria.de/~michael/teapot/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www.moria.de/~michael/teapot/
COMMENT=	Curses based spread sheet program
LICENSE=	teapot-license

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${TEA_DOCSDIR} ${EGDIR}

EGDIR=		share/examples/teapot
EXAMPLES=	examples/asqrt examples/asqrt.README examples/blink \
		examples/counter examples/counter.README examples/life \
		examples/life.README examples/graphtest.sh examples/sqrt \
		examples/sqrt.README
TEA_DOCSDIR=	share/doc/teapot
TEA_DOCS=	doc/teapot.doc doc/teapot.html doc/teapot.ps

do-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} ${MAKE_FLAGS} teapot
	cd ${WRKSRC}/doc && ${MAKE} teapot.doc teapot.html teapot.ps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/teapot ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/teapot.1.en \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/teapot.1
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${EGDIR}
.endfor
.for file in ${TEA_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/${TEA_DOCSDIR}
.endfor

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
