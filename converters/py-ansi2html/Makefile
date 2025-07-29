# $NetBSD: Makefile,v 1.2 2025/07/29 05:28:02 dkazankov Exp $

DISTNAME=	ansi2html-1.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansi2html/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/pycontribs/ansi2html
COMMENT=	Convert text with ANSI color codes to HTML or to LaTeX
LICENSE=	gnu-lgpl-v3 OR mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ansi2html ansi2html-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
