# $NetBSD: Makefile,v 1.4 2025/12/28 20:56:52 adam Exp $

DISTNAME=	sarge-0.1.7.post1
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
