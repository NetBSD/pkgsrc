# $NetBSD: Makefile,v 1.6 2022/01/04 20:52:47 wiz Exp $

DISTNAME=	zope.event-4.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.e/ZopeE/}
PKGREVISION=	1
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
