# $NetBSD: Makefile,v 1.3 2019/06/02 08:41:18 adam Exp $

.include "../../lang/clang/Makefile.common"

PKGNAME=	${DISTNAME:S/cfe/clang-tools-extra/:S/.src//}

COMMENT=	Extra Clang tools

DISTFILES+=	${DEFAULT_DISTFILES}
DISTFILES+=	${DISTNAME:S/cfe/clang-tools-extra/}${EXTRACT_SUFX}

DISTINFO_FILE=	${.CURDIR}/distinfo

BUILD_TARGET=	clang-change-namespace clang-apply-replacements clang-doc
BUILD_TARGET+=	clang-include-fixer clang-move clang-query clang-reorder-fields
BUILD_TARGET+=	clang-tidy clangd modularize pp-trace tool-template
INSTALL_DIRS=	../build/tools/extra

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=ON

REPLACE_PYTHON+=	tools/extra/clang-tidy/tool/clang-tidy-diff.py
REPLACE_PYTHON+=	tools/extra/clang-tidy/tool/run-clang-tidy.py
REPLACE_PYTHON+=	tools/extra/include-fixer/find-all-symbols/tool/run-find-all-symbols.py

.PHONY: inject-clang-tools
post-extract: inject-clang-tools
inject-clang-tools:
	mv ${WRKDIR}/${DISTNAME:S/cfe/clang-tools-extra/} ${WRKSRC}/tools/extra

.include "../../mk/bsd.pkg.mk"
