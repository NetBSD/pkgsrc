# $NetBSD: Makefile,v 1.11 2024/11/11 07:28:31 wiz Exp $

DISTNAME=	zope_hookable-7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/./}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.hookable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.hookable
COMMENT=	Zope hookable
LICENSE=	zpl-2.1

WHEEL_NAME=	${DISTNAME:S/_/./}

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
