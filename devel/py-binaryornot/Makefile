# $NetBSD: Makefile,v 1.7 2023/05/02 17:14:02 wiz Exp $

DISTNAME=	binaryornot-0.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/binaryornot/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/audreyr/binaryornot
COMMENT=	Guess whether a file is binary or text
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
