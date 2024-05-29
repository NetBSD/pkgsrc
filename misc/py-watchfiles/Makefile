# $NetBSD: Makefile,v 1.2 2024/05/29 10:40:00 adam Exp $

DISTNAME=	watchfiles-0.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/watchfiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/samuelcolvin/watchfiles
COMMENT=	Simple, modern and high performance file watching and code reload
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=0.14.16:../../devel/py-maturin
DEPENDS+=	${PYPKGPREFIX}-anyio>=3.0.0:../../devel/py-anyio

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} watchfiles watchfiles-${PYVERSSUFFIX} || ${TRUE}

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
