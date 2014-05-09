# $NetBSD: Makefile,v 1.7 2014/05/09 07:37:19 wiz Exp $

DISTNAME=	v0.7.2
PROPERNAME=	${DISTNAME:S/v/xattr-/}
PKGNAME=	${PYPKGPREFIX}-${PROPERNAME}
PKGREVISION=	2
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

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
