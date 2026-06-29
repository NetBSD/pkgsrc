# $NetBSD: version.mk,v 1.177 2026/06/29 19:14:13 morr Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0747
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s" v<old_version>...HEAD
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
