# $NetBSD: Makefile,v 1.5 2026/01/20 19:50:44 adam Exp $

DISTNAME=	sarge-0.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sarge/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sarge.readthedocs.io/
COMMENT=	Wrapper for subprocess which provides command pipeline functionality
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
