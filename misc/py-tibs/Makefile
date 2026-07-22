# $NetBSD: Makefile,v 1.9 2026/07/22 07:12:21 adam Exp $

DISTNAME=	tibs-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tibs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scott-griffiths/tibs
COMMENT=	Sleek Python library for binary data
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.151.0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=5.2.0:../../devel/py-test-benchmark

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
