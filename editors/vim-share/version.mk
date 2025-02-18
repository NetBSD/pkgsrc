# $NetBSD: version.mk,v 1.154 2025/02/18 21:15:26 morr Exp $

VIM_VERSION=		9.1
VIM_PATCHLEVEL=		1122
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim91

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
