# $NetBSD: Makefile,v 1.5 2021/12/30 13:05:32 adam Exp $

GITHUB_PROJECT=	fecon235
GITHUB_TAG=	v5.17.0722
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S/v//}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_GITHUB:=rsvp/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rsvp/fecon235/
COMMENT=	Computational tools for financial economics
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pandas>0.18:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-pandas-datareader-[0-9]*:../../math/py-pandas-datareader
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-statsmodels-[0-9]*:../../math/py-statsmodels
DEPENDS+=	${PYPKGPREFIX}-sympy-[0-9]*:../../math/py-sympy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-matplotlib, py-scipy

NO_BUILD=		yes
PY_PATCHPLIST=		yes
PYTHON_SELF_CONFLICT=	yes

INSTALLATION_DIRS+=	${PYSITELIB}/fecon235/lib share/doc/fecon235

do-install:
	${INSTALL_DATA} ${WRKSRC}/fecon235.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}/fecon235/
	${INSTALL_DATA} ${WRKSRC}/lib/* \
		${DESTDIR}${PREFIX}/${PYSITELIB}/fecon235/lib/
	cd ${WRKSRC} && \
	for f in CHANGELOG.md README.md LICENSE.md docs/*.ipynb nb/*; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/doc/fecon235/; \
	done

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
