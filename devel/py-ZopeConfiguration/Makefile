# $NetBSD: Makefile,v 1.1 2017/04/25 17:48:12 fhajny Exp $

DISTNAME=	zope.configuration-4.0.3
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
