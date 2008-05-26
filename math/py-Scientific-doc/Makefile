# $NetBSD: Makefile,v 1.8 2008/05/26 02:13:22 joerg Exp $

DISTNAME=	ScientificPython-2.4.5
PKGNAME=	py-${DISTNAME:S/Python/-doc/}
CATEGORIES=	math python
MASTER_SITES=	http://starship.python.net/crew/hinsen/ScientificPython/ \
		http://dirac.cnrs-orleans.fr/programs/ScientificPython/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/hinsen/scientific.html
COMMENT=	Python modules for scientific computing

CONFLICTS+=	py-Scientific-*

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

USE_TOOLS+=	pax

EGDIR=		${PREFIX}/share/examples/py-Scientific
DOCDIR=		${PREFIX}/share/doc/py-Scientific
HTMLDIR=	${PREFIX}/share/doc/html/py-Scientific

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README LICENSE 			\
		Doc/PDF/manual.pdf ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/Doc/HTML && pax -rw -pp -pm . ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/Examples && pax -rw -pp -pm . ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
