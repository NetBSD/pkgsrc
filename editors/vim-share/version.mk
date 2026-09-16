# $NetBSD: version.mk,v 1.181 2026/09/16 23:21:45 morr Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		1116
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s" v<old_version>...HEAD
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
