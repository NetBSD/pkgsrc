# $NetBSD: Makefile,v 1.5 2024/11/13 13:32:25 jperkin Exp $

DISTNAME=	pycddl-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycddl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/pycddl/
COMMENT=	Deserialize CBOR and/or do CDDL schema validation
LICENSE=	mit

TEST_DEPENDS+=		${PYPKGPREFIX}-cbor2>=0:../../devel/py-cbor2
TEST_DEPENDS+=		${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis
TEST_DEPENDS+=		${PYPKGPREFIX}-psutil>=0:../../sysutils/py-psutil
TEST_DEPENDS+=		${PYPKGPREFIX}-test-benchmark>=0:../../devel/py-test-benchmark

USE_LANGUAGES+=		c

# as of 0.6.3
# 1 failed, 14 passed

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
