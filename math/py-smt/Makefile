# $NetBSD: Makefile,v 1.10 2025/04/15 16:31:39 adam Exp $

DISTNAME=	PySMT-0.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PySMT/smt/}
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PySMT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pysmt/pysmt
COMMENT=	Library for SMT formula manipulation and solving
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-z3>=0:../../math/py-z3

USE_LANGUAGES=	c # for testing

WHEEL_NAME=	${DISTNAME:tl}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pysmt-install pysmt-install-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
