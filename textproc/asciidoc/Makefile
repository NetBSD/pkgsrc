# $NetBSD: Makefile,v 1.77 2024/05/29 16:34:34 adam Exp $

DISTNAME=	asciidoc-10.2.0
PKGREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asciidoc/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://asciidoc.org/
COMMENT=	ASCII to formatted document converter
LICENSE=	gnu-gpl-v2

DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DEPENDS+=	getopt-[0-9]*:../../misc/getopt

USE_PKG_RESOURCES=	yes
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
.include "../../lang/python/egg.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
