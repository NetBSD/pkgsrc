# $NetBSD: Makefile,v 1.2 2019/07/03 07:19:03 nia Exp $

DISTNAME=	zope.deferredimport-4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.deferredimport/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.deferredimport
COMMENT=	Imports names that will only be resolved when used in the code
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-zope.proxy>=4.3.1:../../www/py-zope.proxy

USE_LANGUAGES=	#

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
