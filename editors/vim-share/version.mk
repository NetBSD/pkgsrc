# $NetBSD: version.mk,v 1.124 2019/08/03 21:01:11 morr Exp $

VIM_VERSION=		8.1
VIM_PATCHLEVEL=		1778
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.1/
VIM_SUBDIR=		vim81

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
