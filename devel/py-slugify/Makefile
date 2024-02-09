# $NetBSD: Makefile,v 1.9 2024/02/09 06:32:14 adam Exp $

DISTNAME=	python-slugify-8.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-slugify/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/un33k/python-slugify
COMMENT=	Slugify (non-ASCII to ASCII) application that handles Unicode
LICENSE=	mit

PREV_PKGPATH=	devel/py-python-slugify

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-text-unidecode>=1.3:../../textproc/py-text-unidecode

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} slugify slugify-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
