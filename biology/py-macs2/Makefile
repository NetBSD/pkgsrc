# $NetBSD: Makefile,v 1.16 2026/08/25 09:26:21 wiz Exp $

DISTNAME=	MACS2-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-macs2-2.2.9.1
PKGREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=taoliu/}
GITHUB_PROJECT=	MACS
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/macs3-project/MACS
COMMENT=	Algorithm for identifying transcription factor binding sites
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

CYTHONIZE=	${PREFIX}/bin/cythonize-${PYVERSSUFFIX}

WHEEL_NAME=	${DISTNAME:tl}

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

# Distributed .c files do not support python > 3.9
pre-configure:
	${MV} ${WRKSRC}/MACS2/cPosValCalculation.c ${WRKSRC}
	${RM} -f ${WRKSRC}/MACS2/*.c ${WRKSRC}/MACS2/*/*.c
	cd ${WRKSRC} && ${CYTHONIZE} ${WRKSRC}/MACS2/*.pyx
	cd ${WRKSRC} && ${CYTHONIZE} ${WRKSRC}/MACS2/*/*.pyx
	${MV} ${WRKSRC}/cPosValCalculation.c ${WRKSRC}/MACS2

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
