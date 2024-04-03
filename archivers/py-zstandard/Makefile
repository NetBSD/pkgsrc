# $NetBSD: Makefile,v 1.29 2024/04/03 06:56:12 wiz Exp $

DISTNAME=	zstandard-0.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zstandard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/indygreg/python-zstandard
COMMENT=	Zstandard bindings for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.11:../../devel/py-cffi
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_API_DEPENDS.zstd+=	zstd>=1.5.6

# https://github.com/indygreg/python-zstandard/issues/220
post-extract:
	${RM} ${WRKSRC}/zstd/zstd.h
	${LN} -s ${BUILDLINK_DIR}/include/zstd.h ${WRKSRC}/zstd/zstd.h

.include "../../archivers/zstd/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
