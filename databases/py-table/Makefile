# $NetBSD: Makefile,v 1.16 2014/01/25 10:30:00 wiz Exp $

DISTNAME=	pytable-0.8.3a
PKGNAME=	${PYPKGPREFIX}-table-0.8.3a
PKGREVISION=	4
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pytable/}

OWNER=		darcy@NetBSD.org
HOMEPAGE=	http://pytable.sourceforge.net/
COMMENT=	Python RDBMS wrapper for various databases

DEPENDS+=	${PYPKGPREFIX}-basicproperty-[0-9]*:../../lang/py-basicproperty

# py-basicproperty isn't compatible to 3.x
PYTHON_VERSIONS_INCOMPATIBLE=   33

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
