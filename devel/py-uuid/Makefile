# $NetBSD: Makefile,v 1.7 2019/09/02 13:19:37 adam Exp $

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

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.30

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
