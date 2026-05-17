# $NetBSD: version.mk,v 1.170 2026/05/17 17:23:38 morr Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0491
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
