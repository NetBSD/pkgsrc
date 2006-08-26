# $NetBSD: Makefile,v 1.5 2006/08/26 16:42:25 kristerw Exp $
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

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED= 24 23 22

pre-build:
	${RM} ${WRKSRC}/Dependencies/zope.interface-ZopeInterface-3.0.1/zope.interface/*.orig

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
