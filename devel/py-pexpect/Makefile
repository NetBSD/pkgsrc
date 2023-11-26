# $NetBSD: Makefile,v 1.34 2023/11/26 14:45:28 wiz Exp $

DISTNAME=	pexpect-4.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pexpect/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://pexpect.readthedocs.io/
COMMENT=	Pure Python Expect-like module
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ptyprocess>=0.5:../../sysutils/py-ptyprocess

USE_LANGUAGES=	# none

USE_TOOLS+=	bash:test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
