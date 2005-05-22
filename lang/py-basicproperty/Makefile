# $NetBSD: Makefile,v 1.3 2005/05/22 20:08:11 jlam Exp $
#

DISTNAME=	basicproperty-0.6.3a
PKGNAME=	${PYPKGPREFIX}-basicproperty-0.6.3a
CATEGORIES=	python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=basicproperty/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://basicproperty.sf.net/
COMMENT=	Python RDBMS wrapper for various databases

MAKE_ENV+=		MANDIR=${PREFIX}/man
MAKE_ENV+=		BINDIR=${PREFIX}/bin
USE_TOOLS+=		gmake

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
