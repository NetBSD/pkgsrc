# $NetBSD: version.mk,v 1.111 2017/12/03 17:49:14 morr Exp $

VIM_VERSION=		8.0
VIM_PATCHLEVEL=		1365
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.0/
VIM_SUBDIR=		vim80

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
