# $NetBSD: Makefile,v 1.1 2025/07/28 17:26:31 dkazankov Exp $

DISTNAME=	ansi2html-1.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansi2html/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/pycontribs/ansi2html
COMMENT=	Convert text with ANSI color codes to HTML or to LaTeX
LICENSE=	gnu-lgpl-v3 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ansi2html ansi2html-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
