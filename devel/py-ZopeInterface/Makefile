# $NetBSD: Makefile,v 1.14 2012/08/22 11:20:09 drochner Exp $

DISTNAME=	zope.interface-3.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.i/ZopeI/}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/z/zope.interface/

MAINTAINER=	sifu@0xx0.net
HOMEPAGE=	http://pypi.python.org/pypi/zope.interface
COMMENT=	The zope.interface package used in Zope 3 and Twisted
LICENSE=	zpl

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X= yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
