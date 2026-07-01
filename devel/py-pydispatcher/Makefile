# $NetBSD: Makefile,v 1.9 2026/07/01 10:16:19 adam Exp $

DISTNAME=	PyDispatcher-2.0.7
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyDispatcher/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mcfletch/pydispatcher
COMMENT=	Multi-producer-multi-consumer signal dispatching mechanism
LICENSE=	modified-bsd

WHEEL_NAME=	${DISTNAME:tl}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
