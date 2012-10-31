# $NetBSD: Makefile,v 1.3 2012/10/31 11:19:29 asau Exp $
#

DISTNAME=	darcsver-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/d/darcsver/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://pypi.python.org/packages/source/d/darcsver/
COMMENT=	Generate a version number from darcs history
LICENSE=	modified-bsd

DEPENDS+=		${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
