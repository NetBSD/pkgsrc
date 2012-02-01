# $NetBSD: Makefile,v 1.14 2012/02/01 13:07:18 obache Exp $
#

DISTNAME=	pytable-0.8.3a
PKGNAME=	${PYPKGPREFIX}-table-0.8.3a
PKGREVISION=	4
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pytable/}

OWNER=		darcy@NetBSD.org
HOMEPAGE=	http://pytable.sourceforge.net/
COMMENT=	Python RDBMS wrapper for various databases

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-basicproperty-[0-9]*:../../lang/py-basicproperty

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
