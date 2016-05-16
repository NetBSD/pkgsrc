# $NetBSD: Makefile,v 1.1 2016/05/16 14:20:56 nils Exp $

DISTNAME=			binaryornot-0.4.0
GITHUB_PROJECT=			binaryornot
PKGNAME=			${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=			devel python
MASTER_SITES=			${MASTER_SITE_GITHUB:=audreyr/}
EXTRACT_SUFX=			.zip

MAINTAINER=			gde@llew.me
HOMEPAGE=			${MASTER_SITE_GITHUB:=audreyr/binaryornot/}
COMMENT=			Guess whether a file is binary or text
LICENSE=			modified-bsd

USE_LANGUAGES=			#none
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

DEPENDS+=			${PYPKGPREFIX}-chardet>=2.0.0:../../converters/py-chardet

WRKSRC= ${WRKDIR}/${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
