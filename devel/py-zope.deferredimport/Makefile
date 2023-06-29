# $NetBSD: Makefile,v 1.8 2023/06/29 20:11:07 adam Exp $

DISTNAME=	zope.deferredimport-5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.deferredimport/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.deferredimport
COMMENT=	Imports names that will only be resolved when used in the code
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-zope.proxy-[0-9]*:../../www/py-zope.proxy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
