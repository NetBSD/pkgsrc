# $NetBSD: Makefile,v 1.26 2017/05/17 11:23:06 wiz Exp $

DISTNAME=	zope.interface-4.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.i/ZopeI/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.interface/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/zope.interface
COMMENT=	The zope.interface package used in Zope 3 and Twisted
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
