# $NetBSD: Makefile,v 1.1.1.1 2004/12/21 10:59:50 darcy Exp $
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
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
