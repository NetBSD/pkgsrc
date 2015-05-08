# $NetBSD: Makefile,v 1.1 2015/05/08 11:27:44 wiz Exp $

DISTNAME=	gnu-freefont.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	29349

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/gnu-freefont
COMMENT=	Documentation for tex-gnu-freefont
LICENSE=	gnu-gpl-v3

REPLACE_PERL+=		doc/fonts/gnu-freefont/tools/test/MES-Conformance/CheckConformance.pl
REPLACE_PERL+=		doc/fonts/gnu-freefont/tools/test/MES-Conformance/mes-list-expand.pl
REPLACE_PERL+=		doc/fonts/gnu-freefont/tools/utility/KerningNumerals.pl

# we don't want to have a python dependency here
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/generate/buildutils.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/report/OpenType/UnicodeRanges.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/report/OpenType/__init__.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/report/kernclasses.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/report/ligatureLookups.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/report/private_use.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/report/range_report.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/script-menu/nameBySlot.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/script-menu/unnameBySlot.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/test/checkGlyphNumbers.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/test/findBackLayers.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/test/isMonoMono.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/test/ranges/Arabic/arabic_test.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/test/ranges/Arabic/generate_arabic_shaping.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/test/ranges/Arabic/unicode_joining.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/test/validate.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/utility/hex_range.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/utility/metafont/bulk_eps_import.py
#REPLACE_PYTHON+=	doc/fonts/gnu-freefont/tools/utility/special-purpose/makeBraille.py

CHECK_INTERPRETER_SKIP+= 	share/texmf-dist/doc/fonts/gnu-freefont/tools/test/MES-Conformance/CheckConformance.pl
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/test/MES-Conformance/mes-list-expand.pl
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/utility/KerningNumerals.pl
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/generate/buildutils.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/report/OpenType/UnicodeRanges.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/report/OpenType/__init__.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/report/kernclasses.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/report/ligatureLookups.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/report/private_use.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/report/range_report.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/script-menu/nameBySlot.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/script-menu/unnameBySlot.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/test/checkGlyphNumbers.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/test/findBackLayers.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/test/isMonoMono.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/test/ranges/Arabic/arabic_test.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/test/ranges/Arabic/generate_arabic_shaping.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/test/ranges/Arabic/unicode_joining.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/test/validate.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/utility/hex_range.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/utility/metafont/bulk_eps_import.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/gnu-freefont/tools/utility/special-purpose/makeBraille.py

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
