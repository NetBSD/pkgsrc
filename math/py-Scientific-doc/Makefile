# $NetBSD: Makefile,v 1.6 2006/03/04 21:30:08 jlam Exp $

DISTNAME=	ScientificPython-2.4.5
PKGNAME=	py-${DISTNAME:S/Python/-doc/}
CATEGORIES=	math python
MASTER_SITES=	http://starship.python.net/crew/hinsen/ScientificPython/ \
		http://dirac.cnrs-orleans.fr/programs/ScientificPython/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/hinsen/scientific.html
COMMENT=	Python modules for scientific computing

CONFLICTS+=	py-Scientific-*

NO_BUILD=	yes

EGDIR=		${PREFIX}/share/examples/py-Scientific
DOCDIR=		${PREFIX}/share/doc/py-Scientific
HTMLDIR=	${PREFIX}/share/doc/html/py-Scientific

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README LICENSE 			\
		Doc/PDF/manual.pdf ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/Doc/HTML && ${PAX} -rw -pp -pm . ${HTMLDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/Examples && ${PAX} -rw -pp -pm . ${EGDIR}

.include "../../mk/bsd.pkg.mk"
