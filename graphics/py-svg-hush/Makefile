# $NetBSD: Makefile,v 1.1 2026/10/24 10:00:01 adam Exp $

DISTNAME=	py_svg_hush-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py_svg_/svg-/}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py_svg_hush/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jams2/py-svg-hush
COMMENT=	Package for sanitizing SVG files
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
