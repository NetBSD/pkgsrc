# $NetBSD: version.mk,v 1.168 2026/05/06 20:26:50 morr Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0449
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
