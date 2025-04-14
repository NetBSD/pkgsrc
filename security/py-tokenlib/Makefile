# $NetBSD: Makefile,v 1.4 2025/04/14 05:17:12 adam Exp $

DISTNAME=	tokenlib-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tokenlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla-services/tokenlib
COMMENT=	Generic library for managing signed authentication tokens
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
