# $NetBSD: Makefile,v 1.1 2017/06/01 12:04:38 adam Exp $

DISTNAME=	grako-3.99.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/grako/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/neogeny/grako/
COMMENT=	Grammar compiler
LICENSE=	modified-bsd

USE_LANGUAGES=		c

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv grako grako${PYVERSSUFFIX} || ${TRUE}

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
