# $NetBSD: Makefile,v 1.6 2026/06/28 08:07:13 adam Exp $

DISTNAME=	tibs-0.11.0
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
