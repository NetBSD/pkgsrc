# $NetBSD: Makefile,v 1.8 2025/03/05 09:58:12 wiz Exp $

DISTNAME=	zope_testing-5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.testing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.testing
COMMENT=	Zope testing helpers
LICENSE=	zpl-2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
