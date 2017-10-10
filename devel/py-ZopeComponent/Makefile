# $NetBSD: Makefile,v 1.5 2017/10/10 07:42:33 adam Exp $

DISTNAME=	zope.component-4.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.c/ZopeC/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.component/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.zope.org/zopetoolkit/
COMMENT=	Zope Component Architecture modules
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=4.1.0:../../devel/py-ZopeInterface

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
