# $NetBSD: Makefile,v 1.11 2024/12/29 14:58:01 adam Exp $

DISTNAME=	hyperscan-0.7.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hyperscan/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/darvid/python-hyperscan
COMMENT=	CPython extension for hyperscan
LICENSE=	mit

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=68:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.12.0:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.5.0:../../devel/py-test-xdist

USE_TOOLS+=	pkg-config

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/.gitignore
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/hyperscan/hyperscanmodule.c

.include "../../devel/hyperscan/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
