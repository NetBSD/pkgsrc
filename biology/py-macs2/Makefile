# $NetBSD: Makefile,v 1.2 2023/01/29 00:33:04 wiz Exp $

DISTNAME=	MACS2-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-macs2-2.2.7.1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=taoliu/}
GITHUB_PROJECT=	MACS
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/macs3-project/MACS
COMMENT=	Algorithm for identifying transcription factor binding sites
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

PYTHON_VERSIONS_INCOMPATIBLE=	27

CYTHONIZE=	${PREFIX}/bin/cythonize-${PYVERSSUFFIX}

# Distributed .c files do not support python > 3.9
post-extract:
	${MV} ${WRKSRC}/MACS2/cPosValCalculation.c ${WRKSRC}
	${RM} ${WRKSRC}/MACS2/*.c ${WRKSRC}/MACS2/*/*.c
	cd ${WRKSRC} && ${CYTHONIZE} ${WRKSRC}/MACS2/*.pyx
	cd ${WRKSRC} && ${CYTHONIZE} ${WRKSRC}/MACS2/*/*.pyx
	${MV} ${WRKSRC}/cPosValCalculation.c ${WRKSRC}/MACS2

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
