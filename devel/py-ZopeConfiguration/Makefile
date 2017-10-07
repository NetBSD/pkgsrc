# $NetBSD: Makefile,v 1.2 2017/10/07 11:56:21 adam Exp $

DISTNAME=	zope.configuration-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.c/ZopeC/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.configuration/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.zope.org/zopetoolkit/
COMMENT=	Zope Configuration Markup Language
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-ZopeI18NMessageid-[0-9]*:../../devel/py-ZopeI18NMessageid
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-ZopeSchema-[0-9]*:../../devel/py-ZopeSchema

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
