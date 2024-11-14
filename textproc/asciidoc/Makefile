# $NetBSD: Makefile,v 1.82 2024/11/14 22:21:49 wiz Exp $

DISTNAME=	asciidoc-10.2.1
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asciidoc/}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://asciidoc.org/
COMMENT=	ASCII to formatted document converter
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	getopt-[0-9]*:../../misc/getopt

USE_TOOLS+=		pax

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

SUBST_CLASSES+=		pyvers
SUBST_STAGE.pyvers=	pre-configure
SUBST_MESSAGE.pyvers=	Adding Python version suffix.
SUBST_FILES.pyvers=	asciidoc/resources/filters/source/source-highlight-filter.conf
SUBST_SED.pyvers=	-e 's,pygmentize ,pygmentize-${PYVERSSUFFIX} ,g'

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
