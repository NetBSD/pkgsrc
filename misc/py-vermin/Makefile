# $NetBSD: Makefile,v 1.1 2026/11/25 10:29:44 adam Exp $

DISTNAME=	vermin-1.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vermin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/netromdk/vermin
COMMENT=	Concurrently detect the minimum Python versions needed
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80:../../devel/py-setuptools

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	vermin

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
