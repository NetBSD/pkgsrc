# $NetBSD: Makefile,v 1.63 2022/01/24 09:58:21 wiz Exp $

DISTNAME=	asciidoc-10.1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=asciidoc/}
GITHUB_PROJECT=	asciidoc-py3

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://www.asciidoc.org/
COMMENT=	ASCII to formatted document converter
LICENSE=	gnu-gpl-v2

DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	getopt-[0-9]*:../../misc/getopt
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

WRKSRC=		${WRKDIR}/${DISTNAME:S/-/-py-/}

USE_TOOLS+=		pax

SUBST_CLASSES+=		ad
SUBST_STAGE.ad=		pre-configure
SUBST_MESSAGE.ad=	Fixing hard-coded config file paths.
SUBST_FILES.ad=		asciidoc/a2x.py asciidoc/asciidoc.py
SUBST_SED.ad=		-e 's,^\(CONF_DIR\).*=.*,\1="${PREFIX}/share/asciidoc",'

REPLACE_PYTHON+=	asciidoc/a2x.py
REPLACE_PYTHON+=	asciidoc/asciidoc.py
REPLACE_PYTHON+=	asciidoc/resources/filters/code/code-filter.py
REPLACE_PYTHON+=	asciidoc/resources/filters/latex/latex2img.py
REPLACE_PYTHON+=	asciidoc/resources/filters/music/music2png.py
REPLACE_PYTHON+=	asciidoc/resources/filters/graphviz/graphviz2png.py
REPLACE_PYTHON+=	asciidoc/resources/filters/unwraplatex.py
REPLACE_PYTHON+=	tests/testasciidoc.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"

# as of 10.1.1
# 10 failed, 37 passed, 4 warnings
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
