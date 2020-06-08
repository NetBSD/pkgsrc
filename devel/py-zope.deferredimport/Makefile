# $NetBSD: Makefile,v 1.3 2020/06/08 13:00:59 adam Exp $

DISTNAME=	zope.deferredimport-4.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.deferredimport/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.deferredimport
COMMENT=	Imports names that will only be resolved when used in the code
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-zope.proxy-[0-9]*:../../www/py-zope.proxy

USE_LANGUAGES=	#

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
