# $NetBSD: Makefile,v 1.5 2019/10/19 13:58:10 adam Exp $

.include "../../lang/clang/Makefile.common"

PKGNAME=	${DISTNAME:S/cfe/clang-tools-extra/:S/.src//}

COMMENT=	Extra Clang tools

_EXTRA_DIST=		${DISTNAME:S/cfe/clang-tools-extra/}${EXTRACT_SUFX}

DISTFILES=	${DEFAULT_DISTFILES} ${_EXTRA_DIST}

BUILD_TARGET=	clang-change-namespace clang-apply-replacements clang-doc
BUILD_TARGET+=	clang-include-fixer clang-move clang-query clang-reorder-fields
BUILD_TARGET+=	clang-tidy clangd modularize pp-trace tool-template
INSTALL_DIRS=	../build/tools/extra

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=ON

REPLACE_PYTHON+=	tools/extra/clang-include-fixer/find-all-symbols/tool/run-find-all-symbols.py
REPLACE_PYTHON+=	tools/extra/clang-tidy/tool/clang-tidy-diff.py
REPLACE_PYTHON+=	tools/extra/clang-tidy/tool/run-clang-tidy.py

.PHONY: inject-clang-tools
post-extract: inject-clang-tools
inject-clang-tools:
	${MV} ${WRKDIR}/${DISTNAME:S/cfe/clang-tools-extra/} ${WRKSRC}/tools/extra

.include "../../mk/bsd.pkg.mk"
