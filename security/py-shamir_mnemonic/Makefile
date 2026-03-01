# $NetBSD: Makefile,v 1.2 2026/03/01 07:12:29 wiz Exp $

DISTNAME=	shamir_mnemonic-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/shamir-mnemonic/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://pypi.org/project/shamir-mnemonic/
COMMENT=	Reference implementation of SLIP-0039
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-click>=8:../../devel/py-click

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
