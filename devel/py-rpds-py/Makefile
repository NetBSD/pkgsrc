# $NetBSD: Makefile,v 1.8 2023/11/20 18:52:15 adam Exp $

DISTNAME=	rpds_py-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rpds-py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/crate-py/rpds
COMMENT=	Python bindings to Rust's persistent data structures (rpds)
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1.0:../../devel/py-maturin

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/rpds/rpds.so \
	${DESTDIR}${PREFIX}/${PYSITELIB}/rpds/rpds.so
.endif

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
