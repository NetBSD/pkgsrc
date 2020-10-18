# $NetBSD: Makefile,v 1.5 2020/10/18 18:17:54 adam Exp $

DISTNAME=	zope.event-4.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.e/ZopeE/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.event/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.event
COMMENT=	Very basic event publishing system
LICENSE=	zpl-2.1

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
