# $NetBSD: Makefile,v 1.28 2026/08/02 11:30:29 adam Exp $

DISTNAME=	libcst-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libcst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Instagram/LibCST
COMMENT=	Concrete syntax tree with AST-like properties for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.0.0:../../devel/py-setuptools-rust
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.3:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesmith>=0.0.4:../../devel/py-hypothesmith

USE_LANGUAGES=	c c++	# Rust, but needs toolchain for linking

CARGO_WRKSRC=	${WRKSRC}/native
MAKE_ENV+=	CARGO_NET_OFFLINE=true

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

pre-build:
	cd ${WRKSRC}/.cargo && ${LN} -f -s ../native/.cargo/config config

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
