# $NetBSD: Makefile,v 1.8 2026/08/05 02:25:13 adam Exp $

DISTNAME=	authres-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/authres/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/authentication-results-python
COMMENT=	Python implementation of RFC 5451/7001
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
