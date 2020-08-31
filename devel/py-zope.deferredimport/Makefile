# $NetBSD: Makefile,v 1.4 2020/08/31 23:07:02 wiz Exp $

DISTNAME=	zope.deferredimport-4.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.deferredimport/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.deferredimport
COMMENT=	Imports names that will only be resolved when used in the code
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-zope.proxy-[0-9]*:../../www/py-zope.proxy

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

USE_LANGUAGES=	#

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
