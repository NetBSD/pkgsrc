# $NetBSD: Makefile,v 1.7 2026/03/04 09:27:52 adam Exp $

DISTNAME=	uv_build-${UV_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uv-build/}

COMMENT=	The uv build backend

.include "../../devel/py-uv/Makefile.common"

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/uv_build/__init__.py.orig
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} uv-build uv-build-${PYVERSSUFFIX} || ${TRUE}

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
