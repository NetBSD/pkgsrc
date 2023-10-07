# $NetBSD: Makefile,v 1.9 2023/10/07 20:14:31 adam Exp $

DISTNAME=	libcst-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/libcst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Instagram/LibCST
COMMENT=	Concrete syntax tree with AST-like properties for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.0.0:../../devel/py-setuptools-rust
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4.2:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-typing-inspect>=0.4.0:../../devel/py-typing-inspect
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.2:../../textproc/py-yaml

USE_LANGUAGES=	c c++	# Rust, but needs toolchain for linking

PYTHON_VERSIONS_INCOMPATIBLE=	27

CARGO_WRKSRC=	${WRKSRC}/native
MAKE_ENV+=	CARGO_NET_OFFLINE=true

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

pre-build:
	cd ${WRKSRC}/.cargo && ${LN} -f -s ../native/.cargo/config config

CHECK_WRKREF_SKIP+=	${PYSITELIB}/libcst/native.so

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/libcst/native.so \
	${DESTDIR}${PREFIX}/${PYSITELIB}/libcst/native.so
.endif

.include "cargo-depends.mk"

.include "../../lang/python/egg.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
