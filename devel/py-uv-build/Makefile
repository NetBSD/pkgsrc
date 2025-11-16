# $NetBSD: Makefile,v 1.3 2025/11/16 20:35:07 wiz Exp $

DISTNAME=	uv_build-${UV_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uv-build/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/uv
COMMENT=	The uv build backend
LICENSE=	mit OR apache-2.0

CFLAGS+=	-Wno-implicit-function-declaration

.include "../../devel/py-uv/Makefile.common"

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} uv-build uv-build-${PYVERSSUFFIX} || ${TRUE}

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
