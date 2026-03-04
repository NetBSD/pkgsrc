# $NetBSD: Makefile,v 1.3 2026/03/04 09:27:52 adam Exp $

DISTNAME=	uv-${UV_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uv/}

COMMENT=	Extremely fast Python package and project manager

USE_TOOLS+=	gmake

.include "Makefile.common"

post-install:
.for bin in uv uvx
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
