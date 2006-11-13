# $NetBSD: Makefile,v 1.1.1.1 2006/11/13 15:55:55 wulf Exp $
#

DISTNAME=		pyephem-3.7b
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/pyephem/ephem/}
CATEGORIES=		geography
MASTER_SITES=		http://www.rhodesmill.org/brandon/projects/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rhodesmill.org/brandon/projects/pyephem.html
COMMENT=		Scientific-grade astronomical computations for Python

PYDISTUTILSPKG=			true
PYTHON_VERSIONS_ACCEPTED=	23 24

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGNAME}
	${INSTALL} ${WRKSRC}/doc/pyephem-manual.html ${PREFIX}/share/doc/${PKGNAME}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
