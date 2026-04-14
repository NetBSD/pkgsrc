# $NetBSD: Makefile,v 1.14 2026/04/14 12:34:02 adam Exp $

DISTNAME=	types_toml-0.10.8.20260408
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/types-toml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python/typeshed
COMMENT=	Typing stubs for toml
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
