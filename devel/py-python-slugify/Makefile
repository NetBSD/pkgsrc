# $NetBSD: Makefile,v 1.7 2019/08/28 07:57:30 adam Exp $

DISTNAME=	python-slugify-3.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-slugify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/un33k/python-slugify
COMMENT=	Slugify (non-ASCII to ASCII) application that handles Unicode
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-text-unidecode>=1.2:../../textproc/py-text-unidecode

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} slugify slugify-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
