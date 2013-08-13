# $NetBSD: Makefile,v 1.16 2013/08/13 17:42:28 adam Exp $

DISTNAME=	zope.interface-4.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.i/ZopeI/}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/z/zope.interface/
EXTRACT_SUFX=	.zip

MAINTAINER=	sifu@0xx0.net
HOMEPAGE=	http://pypi.python.org/pypi/zope.interface
COMMENT=	The zope.interface package used in Zope 3 and Twisted
LICENSE=	zpl

PYTHON_VERSIONS_INCLUDE_3X= yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
