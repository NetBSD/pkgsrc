# $NetBSD: Makefile,v 1.5 2006/01/06 17:17:40 salo Exp $
#

DISTNAME=	basicproperty-0.6.3a
PKGNAME=	${PYPKGPREFIX}-basicproperty-0.6.3a
PKGREVISION=	1
CATEGORIES=	python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=basicproperty/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://basicproperty.sf.net/
COMMENT=	Python RDBMS wrapper for various databases

MAKE_ENV+=		MANDIR=${PREFIX}/man
MAKE_ENV+=		BINDIR=${PREFIX}/bin
USE_TOOLS+=		gmake

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
