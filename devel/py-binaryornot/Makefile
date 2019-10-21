# $NetBSD: Makefile,v 1.4 2019/10/21 21:50:03 adam Exp $

DISTNAME=	binaryornot-0.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/binaryornot/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/audreyr/binaryornot
COMMENT=	Guess whether a file is binary or text
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-chardet>=3.0.2:../../converters/py-chardet

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
