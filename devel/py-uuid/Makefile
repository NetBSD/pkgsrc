# $NetBSD: Makefile,v 1.8 2022/01/10 20:53:31 wiz Exp $

DISTNAME=	uuid-1.30
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uuid/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.python.org/pypi/uuid
COMMENT=	UUID object and generation functions
LICENSE=	generic-nonlicense

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.30

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
