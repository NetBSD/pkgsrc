# $NetBSD: Makefile,v 1.27 2024/11/11 07:29:00 wiz Exp $

DISTNAME=	xattr-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xattr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xattr/xattr
COMMENT=	Python wrapper for extended filesystem attributes
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=68:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.16.0:../../devel/py-cffi

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} xattr xattr-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
