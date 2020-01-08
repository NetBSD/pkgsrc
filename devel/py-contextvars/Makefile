# $NetBSD: Makefile,v 1.2 2020/01/08 20:12:02 adam Exp $

DISTNAME=	contextvars-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/contextvars/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MagicStack/contextvars
COMMENT=	PEP 567 Backport
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-immutables>=0.9:../../misc/py-immutables

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
