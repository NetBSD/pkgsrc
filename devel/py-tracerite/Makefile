# $NetBSD: Makefile,v 1.3 2025/08/06 04:43:46 adam Exp $

DISTNAME=	tracerite-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tracerite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sanic-org/tracerite
COMMENT=	Human-readable HTML tracebacks for Python exceptions
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-html5tagger>=1.2.1:../../textproc/py-html5tagger

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
