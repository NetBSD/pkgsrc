# $NetBSD: version.mk,v 1.134 2021/07/17 17:49:21 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		3172
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.2/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
