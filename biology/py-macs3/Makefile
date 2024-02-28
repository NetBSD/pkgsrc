# $NetBSD: Makefile,v 1.4 2024/02/28 13:38:48 bacon Exp $

DISTNAME=	macs-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-macs3-3.0.1
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
DEPENDS+=	${PYPKGPREFIX}-hmmlearn>=0.3:../../math/py-hmmlearn
# cykhash>=2.0,<3.0
DEPENDS+=	${PYPKGPREFIX}-cykhash>=2.0:../../devel/py-cykhash
TEST_DEPENDS=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test

USE_TOOLS+=	bash perl:test
REPLACE_BASH=	test/cmdlinetest* test/prockreport test/*.py test/pyprofile*

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

do-test: install
	${RM} -rf ${WRKSRC}/temp
	(cd ${WRKSRC}/test && ./cmdlinetest tag)

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/simde/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
