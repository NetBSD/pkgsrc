# $NetBSD: Makefile,v 1.4 2023/07/01 08:37:43 wiz Exp $

DISTNAME=	cleo-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cleo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-poetry/cleo
COMMENT=	Create beautiful and testable command-line interfaces
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-crashtest>=0.4.1:../../misc/py-crashtest
DEPENDS+=	${PYPKGPREFIX}-rapidfuzz>=2.2.0:../../textproc/py-rapidfuzz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
