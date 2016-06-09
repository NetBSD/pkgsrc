# $NetBSD: Makefile,v 1.2 2016/06/09 06:23:39 wiz Exp $

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
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

DEPENDS+=			${PYPKGPREFIX}-chardet>=2.0.0:../../converters/py-chardet

WRKSRC= ${WRKDIR}/${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
