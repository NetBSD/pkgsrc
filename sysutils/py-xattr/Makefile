# $NetBSD: Makefile,v 1.1 2013/09/30 17:25:51 wiz Exp $

DISTNAME=	v0.7.2
PROPERNAME=	${DISTNAME:S/v/xattr-/}
PKGNAME=	${PYPKGPREFIX}-${PROPERNAME}
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/xattr/xattr/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xattr/xattr/
COMMENT=	Python wrapper for extended filesystem attributes
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../nih/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../nih/py-cparser

DIST_SUBDIR=	xattr

WRKSRC=		${WRKDIR}/${PROPERNAME}
EGG_NAME=	${PROPERNAME}
USE_LANGUAGES=	c
REPLACE_PYTHON=	xattr/tool.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
