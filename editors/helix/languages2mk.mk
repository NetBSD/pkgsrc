# $NetBSD: languages2mk.mk,v 1.1 2022/11/11 20:23:39 nikita Exp $
#
# Simplify extracting the tree-sitter grammars to catch them ahead of build.

DISTFILES?=	${DEFAULT_DISTFILES}
.for dist in ${TREESITTER_DISTFILES}
DISTFILES+=	${dist}
.endfor

.PHONY: print-tree-sitter-depends
print-tree-sitter-depends:
	${RUN}${AWK} -f filter.awk ${WRKSRC}/languages.toml
