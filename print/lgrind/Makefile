# $NetBSD: Makefile,v 1.19 2005/01/17 12:51:29 wiz Exp $

DISTNAME=	lgrind
PKGNAME=	lgrind-3.5
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Source pretty printer for LaTeX

DEPENDS+=	teTeX>=1.0:../../print/teTeX

WRKSRC=		${WRKDIR}/lgrind/source
USE_X11=	yes
NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
NO_CONFIGURE=	yes

pre-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile-prepatch
	${SED} -e '/Id/s|\$$||g' ${WRKSRC}/Makefile-prepatch > ${WRKSRC}/Makefile

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

.include "../../mk/bsd.pkg.mk"
