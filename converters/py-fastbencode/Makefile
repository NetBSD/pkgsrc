# $NetBSD: Makefile,v 1.20 2026/10/29 12:16:59 adam Exp $

DISTNAME=	fastbencode-0.3.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES+=	${MASTER_SITE_PYPI:=f/fastbencode/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://github.com/breezy-team/fastbencode
COMMENT=	Implementation of bencode with optional fast C extensions
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.0.0:../../devel/py-setuptools-rust

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
