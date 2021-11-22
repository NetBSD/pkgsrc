# $NetBSD: Makefile,v 1.18 2021/11/22 09:15:31 adam Exp $

DISTNAME=	xattr-0.9.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xattr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xattr/xattr
COMMENT=	Python wrapper for extended filesystem attributes
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} xattr xattr-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
