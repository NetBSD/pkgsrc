# $NetBSD: Makefile,v 1.6 2025/12/08 19:43:55 bsiegert Exp $

DISTNAME=	uv_build-${UV_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uv-build/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astral-sh/uv
COMMENT=	The uv build backend
LICENSE=	mit OR apache-2.0

.include "../../devel/py-uv/Makefile.common"

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/uv_build/__init__.py.orig
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} uv-build uv-build-${PYVERSSUFFIX} || ${TRUE}

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
