# $NetBSD: Makefile,v 1.20 2023/03/29 09:34:08 wiz Exp $

DISTNAME=	mock-3.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mock/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/testing-cabal/mock
COMMENT=	Python testing framework
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-six>=1.7:../../lang/py-six

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} == 207
DEPENDS+=	${PYPKGPREFIX}-funcsigs>=1:../../devel/py-funcsigs
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
