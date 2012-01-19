# $NetBSD: Makefile,v 1.12 2012/01/19 19:10:40 drochner Exp $
#

DISTNAME=		zope.interface-3.6.7
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/zope.i/ZopeI/}
CATEGORIES=		devel python
MASTER_SITES=		http://pypi.python.org/packages/source/z/zope.interface/
EXTRACT_SUFX=		.zip

MAINTAINER=		sifu@0xx0.net
HOMEPAGE=		http://pypi.python.org/pypi/zope.interface
COMMENT=		The zope.interface package used in Zope 3 and Twisted
LICENSE=		zpl

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
