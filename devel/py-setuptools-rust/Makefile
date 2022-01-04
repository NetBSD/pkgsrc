# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:38 wiz Exp $

DISTNAME=	setuptools-rust-0.10.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=PyO3/}
GITHUB_PROJECT=	setuptools-rust
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/PyO3/setuptools-rust
COMMENT=	Setuptools plugin for Rust support
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.6.0:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-toml>=0.9.0:../../textproc/py-toml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
