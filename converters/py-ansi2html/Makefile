# $NetBSD: Makefile,v 1.4 2026/09/03 06:03:07 adam Exp $

DISTNAME=	ansi2html-1.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansi2html/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/pycontribs/ansi2html
COMMENT=	Convert text with ANSI color codes to HTML or to LaTeX
LICENSE=	gnu-lgpl-v3 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.0:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	ansi2html

pre-test:
	${LN} -fs ${DESTDIR}${PREFIX}/bin/ansi2html-${PYVERSSUFFIX} \
		${BUILDLINK_DIR}/bin/ansi2html

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
