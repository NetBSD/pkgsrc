# $NetBSD: version.mk,v 1.158 2025/12/03 22:52:01 morr Exp $

VIM_VERSION=		9.1
VIM_PATCHLEVEL=		1952
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim91

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
