# $NetBSD: Makefile,v 1.30 2025/07/15 13:22:47 adam Exp $

DISTNAME=	xattr-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xattr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xattr/xattr
COMMENT=	Python wrapper for extended filesystem attributes
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.16.0:../../devel/py-cffi

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} xattr xattr-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
