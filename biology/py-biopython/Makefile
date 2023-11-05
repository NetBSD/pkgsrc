# $NetBSD: Makefile,v 1.11 2023/11/05 23:52:20 wiz Exp $

DISTNAME=	biopython-1.81
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	http://biopython.org/DIST/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://biopython.org/
COMMENT=	Python libraries for computational molecular biology
LICENSE=	biopython

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

USE_TOOLS+=	pax

INSTALLATION_DIRS+=	share/doc/biopython-${PYVERSSUFFIX} share/examples/biopython-${PYVERSSUFFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DESTDIR}${PREFIX}/share/doc/biopython-${PYVERSSUFFIX}
	${INSTALL_DATA} ${WRKSRC}/Doc/Tutorial.pdf ${DESTDIR}${PREFIX}/share/doc/biopython-${PYVERSSUFFIX}
	cd ${WRKSRC}/Doc/examples && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/examples/biopython-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
