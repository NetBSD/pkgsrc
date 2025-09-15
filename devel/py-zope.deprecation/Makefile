# $NetBSD: Makefile,v 1.11 2025/09/15 12:15:29 adam Exp $

DISTNAME=	zope_deprecation-6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.deprecation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.deprecation
COMMENT=	Zope hookable
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
