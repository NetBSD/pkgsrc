# $NetBSD: Makefile,v 1.4 2013/11/26 20:25:42 wiz Exp $

DISTNAME=	v0.7.2
PROPERNAME=	${DISTNAME:S/v/xattr-/}
PKGNAME=	${PYPKGPREFIX}-${PROPERNAME}
PKGREVISION=	1
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

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py27"
PLIST_SUBST+=	SONAME=_cffi__xf4c78acfx6ee6f75
.elif ${PYPKGPREFIX} == "py26"
PLIST_SUBST+=	SONAME=_cffi__x9365fd4fx6ee6f75
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
