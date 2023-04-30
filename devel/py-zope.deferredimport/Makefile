# $NetBSD: Makefile,v 1.7 2023/04/30 12:16:20 wiz Exp $

DISTNAME=	zope.deferredimport-4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.deferredimport/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.deferredimport
COMMENT=	Imports names that will only be resolved when used in the code
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-zope.proxy-[0-9]*:../../www/py-zope.proxy

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	#

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
