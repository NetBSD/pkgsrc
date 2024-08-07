# $NetBSD: Makefile,v 1.7 2024/08/07 19:32:48 wiz Exp $

DISTNAME=	PySMT-0.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PySMT/smt/}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PySMT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pysmt/pysmt
COMMENT=	Library for SMT formula manipulation and solving
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-z3>=0:../../math/py-z3

USE_LANGUAGES=	c # for testing

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pysmt-install pysmt-install-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
