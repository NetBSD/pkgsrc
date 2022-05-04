# $NetBSD: Makefile,v 1.1 2022/05/04 12:38:39 adam Exp $

DISTNAME=	pytest-freezegun-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-freezegun/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ktosiek/pytest-freezegun
COMMENT=	Wrap tests with fixtures in freeze_time
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.3:../../devel/py-freezegun
DEPENDS+=	${PYPKGPREFIX}-test>=3.0.0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
