# $NetBSD: Makefile,v 1.4 2024/08/31 08:47:23 wiz Exp $

DISTNAME=	watchfiles-0.23.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/watchfiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/samuelcolvin/watchfiles
COMMENT=	Simple, modern and high performance file watching and code reload
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=0.14.16:../../devel/py-maturin
DEPENDS+=	${PYPKGPREFIX}-anyio>=3.0.0:../../devel/py-anyio

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} watchfiles watchfiles-${PYVERSSUFFIX} || ${TRUE}

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
