# $NetBSD: Makefile,v 1.7 2017/10/05 06:49:16 adam Exp $

DISTNAME=	attrs-17.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/attrs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.attrs.org/
COMMENT=	Attributes without boilerplate
LICENSE=	mit

USE_LANGUAGES=		# none

# This is a test dependency; disabled because hypothesis requires attrs
#BUILD_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
