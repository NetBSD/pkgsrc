# $NetBSD: Makefile,v 1.6 2019/08/28 05:42:15 wiz Exp $

DISTNAME=	python-slugify-3.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-slugify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/un33k/python-slugify
COMMENT=	Slugify (non-ASCII to ASCII) application that handles Unicode
LICENSE=	mit

USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-text-unidecode>=1.2:../../textproc/py-text-unidecode

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/slugify \
		${DESTDIR}${PREFIX}/bin/slugify${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
