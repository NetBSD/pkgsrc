# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:28 joerg Exp $
#

DISTNAME=		ZopeInterface-3.0.1
PKGNAME=		${PYPKGPREFIX}-ZopeInterface-3.0.1
PKGREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=		http://zope.org/Products/ZopeInterface/3.0.1final/
EXTRACT_SUFX=		.tgz

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://www.zope.org/
COMMENT=		The zope.interface package used in Zope 3 and Twisted

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

pre-build:
	${RM} ${WRKSRC}/Dependencies/zope.interface-ZopeInterface-3.0.1/zope.interface/*.orig

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
