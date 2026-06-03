# $NetBSD: version.mk,v 1.174 2026/06/03 22:33:11 morr Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0593
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s" v<old_version>...HEAD
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
