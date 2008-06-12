# $NetBSD: Makefile,v 1.8 2008/06/12 02:14:33 joerg Exp $
#

DISTNAME=	basicproperty-0.6.3a
PKGNAME=	${PYPKGPREFIX}-basicproperty-0.6.3a
PKGREVISION=	2
CATEGORIES=	python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=basicproperty/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://basicproperty.sourceforge.net/
COMMENT=	Python RDBMS wrapper for various databases

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=		MANDIR=${PREFIX}/man
MAKE_ENV+=		BINDIR=${PREFIX}/bin
USE_TOOLS+=		gmake

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX:Q}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
