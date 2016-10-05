# $NetBSD: Makefile,v 1.2 2016/10/05 06:25:16 wiz Exp $

DISTNAME=	uuid-1.30
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uuid/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/pypi/uuid
COMMENT=	UUID object and generation functions
LICENSE=	generic-nonlicense

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 1.30

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
