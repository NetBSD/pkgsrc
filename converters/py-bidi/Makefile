# $NetBSD: Makefile,v 1.5 2025/10/09 11:51:41 wiz Exp $

DISTNAME=	python_bidi-0.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python_//}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-bidi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MeirKriheli/python-bidi
COMMENT=	Pure Python implementation of the BiDi layout algorithm
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1:../../devel/py-maturin

# https://github.com/MeirKriheli/python-bidi/issues/36
MAKE_ENV+=	PYO3_USE_ABI3_FORWARD_COMPATIBILITY=1

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pybidi pybidi-${PYVERSSUFFIX} || ${TRUE}

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
