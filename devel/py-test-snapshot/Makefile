# $NetBSD: Makefile,v 1.4 2025/04/12 21:10:58 adam Exp $

DISTNAME=	pytest-snapshot-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-snapshot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/joseph-roitman/pytest-snapshot
COMMENT=	Plugin for snapshot testing with pytest
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

# 5 failed, 102 passed, 1 xfailed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
