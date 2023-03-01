# $NetBSD: Makefile,v 1.1 2023/03/01 18:35:29 adam Exp $

DISTNAME=	maturin-0.14.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/maturin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyO3/maturin
COMMENT=	Build and publish crates with pyo3, rust-cpython and cffi bindings
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.4.0:../../devel/py-setuptools-rust
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.36.2:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} maturin maturin-${PYVERSSUFFIX} || ${TRUE}

.include "cargo-depends.mk"

.include "../../lang/python/egg.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
