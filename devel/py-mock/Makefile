# $NetBSD: Makefile,v 1.16 2019/05/05 04:55:10 adam Exp $

DISTNAME=	mock-3.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mock/}

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	https://github.com/testing-cabal/mock
COMMENT=	Python testing framework
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-six>=1.7:../../lang/py-six

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-funcsigs>=1:../../devel/py-funcsigs
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
