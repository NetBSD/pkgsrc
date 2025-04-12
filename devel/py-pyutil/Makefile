# $NetBSD: Makefile,v 1.33 2025/04/12 20:03:46 adam Exp $

DISTNAME=	pyutil-3.3.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyutil/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/tpltnt/pyutil
COMMENT=	Collection of mature utilities for Python programmers
LICENSE=	gnu-gpl-v2

CONFLICTS+=	passphrase-[0-9]*

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-versioneer-[0-9]*:../../devel/py-versioneer
DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.1.0:../../converters/py-simplejson
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.3.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted>=0:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
