# $NetBSD: Makefile,v 1.2 2020/07/08 14:58:01 adam Exp $

DISTNAME=	python-slugify-4.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-slugify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/un33k/python-slugify
COMMENT=	Slugify (non-ASCII to ASCII) application that handles Unicode
LICENSE=	mit

PREV_PKGPATH=	devel/py-python-slugify

DEPENDS+=	${PYPKGPREFIX}-text-unidecode>=1.3:../../textproc/py-text-unidecode

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} slugify slugify-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
