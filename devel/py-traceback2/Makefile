# $NetBSD: Makefile,v 1.10 2026/01/06 11:18:43 wiz Exp $

DISTNAME=		traceback2-1.4.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=		${MASTER_SITE_PYPI:=t/traceback2/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/traceback2
COMMENT=		Backport of the traceback module to older Python versions
LICENSE=		python-software-foundation

DEPENDS+=		${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx via py-pbr

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
