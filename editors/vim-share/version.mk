# $NetBSD: version.mk,v 1.178 2026/07/25 18:15:50 morr Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0854
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s" v<old_version>...HEAD
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
