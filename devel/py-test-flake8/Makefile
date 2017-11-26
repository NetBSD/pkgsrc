# $NetBSD: Makefile,v 1.2 2017/11/26 17:17:49 adam Exp $

DISTNAME=	pytest-flake8-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-flake8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tholo/pytest-flake8
COMMENT=	Plugin plugin to check FLAKE8 requirements
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-flake8>=3.5:../../devel/py-flake8
DEPENDS+=	${PYPKGPREFIX}-test>=3.2:../../devel/py-test

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
