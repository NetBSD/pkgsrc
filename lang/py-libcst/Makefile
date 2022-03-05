# $NetBSD: Makefile,v 1.2 2022/03/05 11:23:11 wiz Exp $

DISTNAME=	libcst-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libcst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Instagram/LibCST
COMMENT=	Concrete syntax tree with AST-like properties for Python
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.0.0:../../devel/py-setuptools-rust
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.2:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-typing-inspect>=0.4.0:../../devel/py-typing-inspect
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.2:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "cargo-depends.mk"
# for updating cargo-depends, uncomment the next line since Cargo.lock lives there
#WRKSRC=		${WRKDIR}/${DISTNAME}/native

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
RUST_PEG_REV=	4b146b4b78a80c07e43d7ace2d97f65bfde279a8
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	rust-peg-${RUST_PEG_REV}.tar.gz
SITES.rust-peg-${RUST_PEG_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=kevinmehall/}rust-peg/archive/${RUST_PEG_REV}.tar.gz

USE_LANGUAGES=		c c++   # Rust, but needs toolchain for linking
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
	mv ${WRKDIR}/rust-peg* ${WRKDIR}/rust-peg

CHECK_WRKREF_SKIP+=	${PYSITELIB}/libcst/native.so

.include "../../lang/python/egg.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
