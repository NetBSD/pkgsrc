# $NetBSD: Makefile,v 1.13 2024/05/24 15:15:44 adam Exp $

DISTNAME=	libcst-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libcst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Instagram/LibCST
COMMENT=	Concrete syntax tree with AST-like properties for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.0.0:../../devel/py-setuptools-rust
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.2:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesmith>=0.0.4:../../devel/py-hypothesmith

USE_LANGUAGES=	c c++	# Rust, but needs toolchain for linking

PYTHON_VERSIONS_INCOMPATIBLE=	27

CARGO_WRKSRC=	${WRKSRC}/native
MAKE_ENV+=	CARGO_NET_OFFLINE=true

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

pre-build:
	cd ${WRKSRC}/.cargo && ${LN} -f -s ../native/.cargo/config config

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
