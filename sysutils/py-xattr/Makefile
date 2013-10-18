# $NetBSD: Makefile,v 1.3 2013/10/18 11:57:35 wiz Exp $

DISTNAME=	v0.7.2
PROPERNAME=	${DISTNAME:S/v/xattr-/}
PKGNAME=	${PYPKGPREFIX}-${PROPERNAME}
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/xattr/xattr/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xattr/xattr/
COMMENT=	Python wrapper for extended filesystem attributes
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser

DIST_SUBDIR=	xattr

WRKSRC=		${WRKDIR}/${PROPERNAME}
EGG_NAME=	${PROPERNAME}
USE_LANGUAGES=	c
REPLACE_PYTHON=	xattr/tool.py

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py27"
PLIST_SUBST+=	SONAME=_cffi__x2654de55x6ee6f75
.elif ${PYPKGPREFIX} == "py26"
PLIST_SUBST+=	SONAME=_cffi__x41f6a9d5x6ee6f75
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
