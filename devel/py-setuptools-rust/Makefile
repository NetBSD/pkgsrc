# $NetBSD: Makefile,v 1.20 2024/10/03 08:41:44 adam Exp $

DISTNAME=	setuptools_rust-1.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/setuptools-rust/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/PyO3/setuptools-rust
COMMENT=	Setuptools plugin for Rust support
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.3.2:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.8.2:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-setuptools>=62.4:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
