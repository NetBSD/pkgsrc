# $NetBSD: Makefile,v 1.15 2019/04/26 13:14:15 maya Exp $

DISTNAME=	v0.7.6
PROPERNAME=	${DISTNAME:S/v/xattr-/}
PKGNAME=	${PYPKGPREFIX}-${PROPERNAME}
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/xattr/xattr/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xattr/xattr/
COMMENT=	Python wrapper for extended filesystem attributes
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi>=0.8.1:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser

DIST_SUBDIR=	xattr

WRKSRC=		${WRKDIR}/${PROPERNAME}
EGG_NAME=	${PROPERNAME}
USE_LANGUAGES=	c
REPLACE_PYTHON=	xattr/tool.py

# XXX: builds, installs, but cannot be executed
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/xattr \
		${DESTDIR}${PREFIX}/bin/xattr-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
