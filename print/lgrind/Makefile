# $NetBSD: Makefile,v 1.11 2001/02/17 17:51:46 wiz Exp $

DISTNAME=	lgrind
PKGNAME=	lgrind-3.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwise@netbsd.org
COMMENT=	Source pretty printer for LaTeX

DEPENDS+=	teTeX-1.0.*:../../print/teTeX

USE_X11=	yes
NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL
WRKSRC=		${WRKDIR}/lgrind/source
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
