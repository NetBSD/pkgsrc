# $NetBSD: Makefile,v 1.9 2023/03/29 09:34:05 wiz Exp $

DISTNAME=	atpublic-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/atpublic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://public.readthedocs.io/
COMMENT=	@public decorator for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 308
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
