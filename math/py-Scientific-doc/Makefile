# $NetBSD: Makefile,v 1.1.1.1 2002/01/17 12:00:11 drochner Exp $

DISTNAME=	ScientificPython-2.2
PKGNAME=	py-Scientific-doc-2.2
CATEGORIES=	math
MASTER_SITES=	http://starship.python.net/crew/hinsen/ \
		http://dirac.cnrs-orleans.fr/programs/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://starship.python.net/crew/hinsen/scientific.html
COMMENT=	Python modules for scientific computing

CONFLICTS+=	py-Scientific-*

NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/py-Scientific
	cd ${WRKSRC} && ${INSTALL_DATA} README COPYRIGHT 		\
		Doc/PDF/manual.pdf ${PREFIX}/share/doc/py-Scientific/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/py-Scientific
	${INSTALL_DATA} ${WRKSRC}/Doc/HTML/* 				\
	${PREFIX}/share/doc/html/py-Scientific/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-Scientific
	${INSTALL_DATA} ${WRKSRC}/Examples/* 				\
	${PREFIX}/share/examples/py-Scientific/

.include "../../mk/bsd.pkg.mk"
