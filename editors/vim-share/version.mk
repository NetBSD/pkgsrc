# $NetBSD: version.mk,v 1.155 2025/03/05 16:55:15 morr Exp $

VIM_VERSION=		9.1
VIM_PATCHLEVEL=		1170
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim91

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
