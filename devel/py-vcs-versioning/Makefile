# $NetBSD: Makefile,v 1.1 2026/03/29 18:46:13 wiz Exp $

DISTNAME=	vcs_versioning-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vcs_versioning/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/setuptools-scm
COMMENT=	Manage your versions by vcs metadata
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 1.1.1
# 3 failed, 297 passed, 109 skipped, 3 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
