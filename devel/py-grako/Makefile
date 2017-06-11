# $NetBSD: Makefile,v 1.2 2017/06/11 06:59:18 adam Exp $

DISTNAME=	grako-3.99.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grako/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/neogeny/grako/
COMMENT=	Grammar compiler
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=		c

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv grako grako${PYVERSSUFFIX} || ${TRUE}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
