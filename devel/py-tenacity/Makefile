# $NetBSD: Makefile,v 1.11 2024/12/27 20:53:35 adam Exp $

DISTNAME=	tenacity-9.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tenacity/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jd/tenacity
COMMENT=	Retry code until it succeeds
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=4.5:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-typeguard-[0-9]*:../../devel/py-typeguard

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
