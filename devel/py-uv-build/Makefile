# $NetBSD: Makefile,v 1.1 2025/09/22 17:37:20 adam Exp $

DISTNAME=	uv_build-0.8.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uv-build/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/uv
COMMENT=	The uv build backend
LICENSE=	mit OR apache-2.0

.include "../../devel/py-uv/Makefile.common"

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} uv-build uv-build-${PYVERSSUFFIX} || ${TRUE}

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
