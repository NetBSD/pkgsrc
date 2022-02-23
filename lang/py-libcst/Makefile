# $NetBSD: Makefile,v 1.1 2022/02/23 11:32:52 wiz Exp $

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

CHECK_WRKREF_SKIP+=	${PYSITELIB}/libcst/native.so

.include "../../lang/python/egg.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
