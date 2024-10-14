# $NetBSD: Makefile,v 1.9 2024/10/14 06:45:32 wiz Exp $

DISTNAME=	MACS2-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-macs2-2.2.9.1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=taoliu/}
GITHUB_PROJECT=	MACS
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/macs3-project/MACS
COMMENT=	Algorithm for identifying transcription factor binding sites
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

CYTHONIZE=	${PREFIX}/bin/cythonize-${PYVERSSUFFIX}

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
