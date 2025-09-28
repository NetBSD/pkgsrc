# $NetBSD: Makefile,v 1.2 2025/09/28 19:31:47 wiz Exp $

DISTNAME=	mnemonic-0.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mnemonic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/mnemonic/
COMMENT=	Reference implementation of BIP-0039
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
