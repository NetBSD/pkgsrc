# $NetBSD: version.mk,v 1.156.4.1 2025/07/20 14:41:59 maya Exp $

VIM_VERSION=		9.1
VIM_PATCHLEVEL=		1572
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim91

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
