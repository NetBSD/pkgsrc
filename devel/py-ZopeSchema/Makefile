# $NetBSD: Makefile,v 1.2 2017/10/07 11:51:47 adam Exp $

DISTNAME=	zope.schema-4.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.s/ZopeS/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.schema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.zope.org/zopetoolkit/
COMMENT=	Zope Interface extension for defining data schemas
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-ZopeEvent-[0-9]*:../../devel/py-ZopeEvent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=3.6.0:../../devel/py-ZopeInterface

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
