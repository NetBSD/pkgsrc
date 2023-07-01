# $NetBSD: Makefile,v 1.9 2023/07/01 08:37:33 wiz Exp $

DISTNAME=	biopython-1.79
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	http://biopython.org/DIST/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://biopython.org/
COMMENT=	Python libraries for computational molecular biology
LICENSE=	biopython

USE_TOOLS+=	pax

INSTALLATION_DIRS+=	share/doc/biopython-${PYVERSSUFFIX} share/examples/biopython-${PYVERSSUFFIX}

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DESTDIR}${PREFIX}/share/doc/biopython-${PYVERSSUFFIX}
	${INSTALL_DATA} ${WRKSRC}/Doc/Tutorial.pdf ${DESTDIR}${PREFIX}/share/doc/biopython-${PYVERSSUFFIX}
	cd ${WRKSRC}/Doc/examples && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/examples/biopython-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
