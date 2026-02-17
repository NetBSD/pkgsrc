# $NetBSD: Makefile,v 1.1 2026/02/17 21:59:11 wiz Exp $

DISTNAME=	python-unidiff-0.7.5
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=matiasb/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	python-unidiff

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/unidiff
COMMENT=	Unified diff python parsing/metadata extraction library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	${RUN} ${MV} ${DESTDIR}${PREFIX}/bin/unidiff \
		${DESTDIR}${PREFIX}/bin/unidiff${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
