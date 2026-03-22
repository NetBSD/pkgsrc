# $NetBSD: version.mk,v 1.163 2026/03/22 16:52:46 morr Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0219
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
