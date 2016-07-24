# $NetBSD: Makefile,v 1.10 2016/07/24 20:44:51 rillig Exp $

DISTNAME=	ScientificPython-2.4.5
PKGNAME=	py-${DISTNAME:S/Python/-doc/}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://starship.python.net/crew/hinsen/ScientificPython/ \
		http://dirac.cnrs-orleans.fr/programs/ScientificPython/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://starship.python.net/crew/hinsen/scientific.html
COMMENT=	Python modules for scientific computing

CONFLICTS+=	py-Scientific-*

NO_BUILD=	yes
USE_TOOLS+=	pax
AUTO_MKDIRS=	yes

EGDIR=		${PREFIX}/share/examples/py-Scientific
DOCDIR=		${PREFIX}/share/doc/py-Scientific
HTMLDIR=	${PREFIX}/share/doc/py-Scientific/HTML

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} README LICENSE 			\
		Doc/PDF/manual.pdf ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/Doc/HTML && pax -rw -pp -pm . ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/Examples && pax -rw -pp -pm . ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
