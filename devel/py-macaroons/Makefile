# $NetBSD: Makefile,v 1.8 2026/07/01 06:06:41 adam Exp $

DISTNAME=	pymacaroons-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymacaroons/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/ecordell/pymacaroons
COMMENT=	Python implementation of Macaroons
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.1.2:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-six>=1.8.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
