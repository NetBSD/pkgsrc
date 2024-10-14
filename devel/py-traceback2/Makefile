# $NetBSD: Makefile,v 1.7 2024/10/14 06:45:42 wiz Exp $

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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
