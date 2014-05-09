# $NetBSD: Makefile,v 1.51 2014/05/09 07:37:17 wiz Exp $

DISTNAME=	reportlab-2.7
DISTFILES=	${DEFAULT_DISTFILES} pfbfer.zip
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	http://www.reportlab.com/ftp/
SITES.pfbfer.zip=	http://www.reportlab.com/ftp/fonts/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	Powerful PDF-generating toolkit for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	{${PYPKGPREFIX}-imaging-[0-9]*,${PYPKGPREFIX}-Pillow-[0-9]*}:../../graphics/py-imaging

EXTRACT_DIR.pfbfer.zip=	${WRKSRC}/src/reportlab/fonts

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.7; py-imaging

REPLACE_PYTHON+=	demos/tests/testdemos.py
REPLACE_PYTHON+=	docs/genAll.py
REPLACE_PYTHON+=	docs/reference/genreference.py
REPLACE_PYTHON+=	docs/userguide/genuserguide.py
REPLACE_PYTHON+=	src/reportlab/graphics/barcode/test.py
REPLACE_PYTHON+=	src/reportlab/graphics/testdrawings.py
REPLACE_PYTHON+=	src/reportlab/graphics/testshapes.py
REPLACE_PYTHON+=	src/reportlab/graphics/widgets/table.py
REPLACE_PYTHON+=	src/reportlab/lib/__init__.py
REPLACE_PYTHON+=	src/reportlab/lib/corp.py
REPLACE_PYTHON+=	src/reportlab/lib/fonts.py
REPLACE_PYTHON+=	src/reportlab/lib/formatters.py
REPLACE_PYTHON+=	src/reportlab/lib/logger.py
REPLACE_PYTHON+=	src/reportlab/lib/normalDate.py
REPLACE_PYTHON+=	src/reportlab/lib/pagesizes.py
REPLACE_PYTHON+=	src/reportlab/lib/randomtext.py
REPLACE_PYTHON+=	src/reportlab/lib/set_ops.py
REPLACE_PYTHON+=	src/reportlab/lib/units.py
REPLACE_PYTHON+=	src/reportlab/pdfgen/pycanvas.py
REPLACE_PYTHON+=	src/rl_addons/renderPM/setup.py
REPLACE_PYTHON+=	tests/runAll.py
REPLACE_PYTHON+=	tests/test_docstrings.py
REPLACE_PYTHON+=	tests/test_encrypt.py
REPLACE_PYTHON+=	tests/test_geomutils.py
REPLACE_PYTHON+=	tests/test_hello.py
REPLACE_PYTHON+=	tests/test_images.py
REPLACE_PYTHON+=	tests/test_invariant.py
REPLACE_PYTHON+=	tests/test_pdfbase_postscript.py
REPLACE_PYTHON+=	tests/test_pdfgen_callback.py
REPLACE_PYTHON+=	tests/test_pdfgen_general.py
REPLACE_PYTHON+=	tests/test_pdfgen_pycanvas.py
REPLACE_PYTHON+=	tests/test_platypus_paraparser.py
REPLACE_PYTHON+=	tests/test_platypus_tables.py
REPLACE_PYTHON+=	tests/test_renderSVG.py
REPLACE_PYTHON+=	tests/test_source_chars.py
REPLACE_PYTHON+=	tests/test_utils.py
REPLACE_PYTHON+=	tools/docco/docpy.py
REPLACE_PYTHON+=	tools/docco/graphdocpy.py
REPLACE_PYTHON+=	tools/docco/rl_doc_utils.py
REPLACE_PYTHON+=	tools/pythonpoint/pythonpoint.py

do-test:
	${RUN}cd ${WRKSRC};${PYTHONBIN} setup.py tests

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
