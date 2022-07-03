# $NetBSD: Makefile,v 1.6 2022/07/03 12:13:07 wiz Exp $

DISTNAME=	binaryornot-0.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/binaryornot/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/audreyr/binaryornot
COMMENT=	Guess whether a file is binary or text
LICENSE=	modified-bsd

PYTHON_VERSIONED_DEPENDENCIES=	chardet

USE_LANGUAGES=	# none

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
