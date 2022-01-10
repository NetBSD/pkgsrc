# $NetBSD: Makefile,v 1.27 2022/01/10 20:50:47 wiz Exp $

DISTNAME=	pytable-0.8.3a
PKGNAME=	${PYPKGPREFIX}-table-0.8.3a
PKGREVISION=	5
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pytable/}

OWNER=		darcy@NetBSD.org
HOMEPAGE=	http://pytable.sourceforge.net/
COMMENT=	Python RDBMS wrapper for various databases

DEPENDS+=	${PYPKGPREFIX}-basicproperty-[0-9]*:../../lang/py-basicproperty

# py-basicproperty isn't compatible to 3.x
PYTHON_VERSIONS_ACCEPTED=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
