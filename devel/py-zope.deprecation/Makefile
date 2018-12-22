# $NetBSD: Makefile,v 1.2 2018/12/22 09:08:48 adam Exp $

DISTNAME=	zope.deprecation-4.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.deprecation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/zopefoundation/zope.deprecation
COMMENT=	Zope hookable
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
