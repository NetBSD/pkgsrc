# $NetBSD: Makefile,v 1.7 2024/10/14 22:21:16 bacon Exp $

DISTNAME=	macs-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-macs3-3.0.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=macs3-project/}
GITHUB_PROJECT=	MACS
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/macs3-project/MACS
COMMENT=	Peak caller aimed at transcription factor binding sites
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.11.1:../../math/py-scipy
# cykhash>=2.0,<3.0
DEPENDS+=	${PYPKGPREFIX}-cykhash>=2.0:../../devel/py-cykhash
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=1.3:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-hmmlearn>=0.3.2:../../math/py-hmmlearn
TEST_DEPENDS=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test

USE_TOOLS+=	bash perl:test
REPLACE_BASH=	test/cmdlinetest* test/prockreport test/*.py test/pyprofile*

PYTHON_VERSIONS_INCOMPATIBLE=	27 	# Does not build

do-test: install
	${RM} -rf ${WRKSRC}/temp
	(cd ${WRKSRC}/test && ./cmdlinetest tag)

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/simde/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
