# $NetBSD: Makefile,v 1.11 2008/04/25 20:39:08 joerg Exp $
#

DISTNAME=	pytable-0.8.3a
PKGNAME=	${PYPKGPREFIX}-table-0.8.3a
PKGREVISION=	3
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pytable/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://pytable.sourceforge.net/
COMMENT=	Python RDBMS wrapper for various databases

DEPENDS+=	${PYPKGPREFIX}-basicproperty-[0-9]*:../../lang/py-basicproperty

MAKE_ENV+=		MANDIR=${PREFIX}/man
MAKE_ENV+=		BINDIR=${PREFIX}/bin
USE_TOOLS+=		gmake

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
