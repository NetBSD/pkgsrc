# $NetBSD: Makefile,v 1.5 1999/09/08 18:55:59 jwise Exp $

DISTNAME=	lgrind
PKGNAME=	lgrind-3.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwise@netbsd.org

DEPENDS=	teTeX-1.0.6:../../print/teTeX

USE_X11=	yes
MIRROR_DISTFILE=no
WRKSRC=		${WRKDIR}/lgrind/source
NO_CONFIGURE=	yes

pre-build:
	(cd ${WRKSRC}/.. ; ${PREFIX}/bin/latex lgrind.ins)
	(cd ${WRKSRC}/.. ; ${PREFIX}/bin/latex lgrind.dtx)
	${MV} ${WRKSRC}/lgrind.1 ${WRKSRC}/lgrind.1.bak
	${MV} ${WRKSRC}/lgrindef.5 ${WRKSRC}/lgrindef.5.bak
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${WRKSRC}/lgrind.1.bak > ${WRKSRC}/lgrind.1
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${WRKSRC}/lgrindef.5.bak > ${WRKSRC}/lgrindef.5

pre-install:
	-mkdir ${PREFIX}/share/texmf/tex/latex/lgrind
	-mkdir ${PREFIX}/share/texmf/doc/latex/lgrind

post-install:
	${PREFIX}/bin/texconfig rehash

.include <../../mk/bsd.pkg.mk>
