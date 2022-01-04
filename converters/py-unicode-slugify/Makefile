# $NetBSD: Makefile,v 1.2 2022/01/04 20:52:40 wiz Exp $

DISTNAME=	unicode-slugify-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/unicode-slugify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/unicode-slugify
COMMENT=	Slug generator that turns strings into unicode slugs
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
