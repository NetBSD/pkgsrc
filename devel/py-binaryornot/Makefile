# $NetBSD: Makefile,v 1.5 2022/01/04 20:52:52 wiz Exp $

DISTNAME=	binaryornot-0.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
