# $NetBSD: version.mk,v 1.161 2026/02/28 16:11:28 morr Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0077
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
