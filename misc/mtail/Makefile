# $NetBSD: Makefile,v 1.2 2001/06/04 12:09:46 zuntum Exp $
#

DISTNAME=	mtail-1.0.0
CATEGORIES=	misc
MASTER_SITES=	http://matt.immute.net/src/mtail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://matt.immute.net/src/mtail/
COMMENT=	small tail workalike that performs output coloring

DEPENDS+=	python>=1.5:../../lang/python

NO_BUILD=	yes

post-patch:
	${SED} "s,/usr/bin/python,${LOCALBASE}/bin/python,"		\
		${WRKSRC}/mtail > ${WRKSRC}/mtail.done
	${MV} ${WRKSRC}/mtail.done ${WRKSRC}/mtail

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mtail ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mtail.README
	${INSTALL_DATA} ${WRKSRC}/mtailrc.sample ${PREFIX}/share/examples

.include "../../mk/bsd.pkg.mk"
