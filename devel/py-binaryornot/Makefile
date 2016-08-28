# $NetBSD: Makefile,v 1.3 2016/08/28 15:48:29 wiz Exp $

DISTNAME=			binaryornot-0.4.0
GITHUB_PROJECT=			binaryornot
PKGNAME=			${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=			devel python
MASTER_SITES=			${MASTER_SITE_GITHUB:=audreyr/}
EXTRACT_SUFX=			.zip

MAINTAINER=			gde@llew.me
HOMEPAGE=			https://github.com/audreyr/binaryornot/
COMMENT=			Guess whether a file is binary or text
LICENSE=			modified-bsd

USE_LANGUAGES=			#none

DEPENDS+=			${PYPKGPREFIX}-chardet>=2.0.0:../../converters/py-chardet

WRKSRC= ${WRKDIR}/${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
