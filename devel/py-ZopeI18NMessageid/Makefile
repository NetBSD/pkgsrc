# $NetBSD: Makefile,v 1.5 2020/06/08 13:27:23 adam Exp $

DISTNAME=	zope.i18nmessageid-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/zope.i18nm/ZopeI18NM/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zope.i18nmessageid/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zopefoundation/zope.i18nmessageid
COMMENT=	Zope Message Identifiers for internationalization
LICENSE=	zpl-2.1

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
