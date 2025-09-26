# $NetBSD: Makefile,v 1.2 2025/09/26 13:50:33 adam Exp $

DISTNAME=	uv-${UV_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/uv
COMMENT=	Extremely fast Python package and project manager
LICENSE=	mit OR apache-2.0

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
