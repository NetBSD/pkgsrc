# $NetBSD: Makefile,v 1.6 2021/02/16 18:48:37 adam Exp $

DISTNAME=	atpublic-2.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/atpublic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://public.readthedocs.io/
COMMENT=	@public decorator for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
