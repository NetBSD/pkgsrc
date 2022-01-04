# $NetBSD: Makefile,v 1.7 2022/01/04 20:53:42 wiz Exp $

DISTNAME=	pytest-relaxed-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-relaxed/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bitprophet/pytest-relaxed
COMMENT=	Relaxed test discovery/organization for pytest
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-decorator>=4.0.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-six>=1.0.0:../../lang/py-six

PYTHON_VERSIONED_DEPENDENCIES=	test

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
