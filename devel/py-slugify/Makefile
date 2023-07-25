# $NetBSD: Makefile,v 1.6 2023/07/25 13:20:33 adam Exp $

DISTNAME=	python-slugify-8.0.1
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

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} slugify slugify-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
