# $NetBSD: version.mk,v 1.110 2017/10/24 11:04:03 morr Exp $

VIM_VERSION=		8.0
VIM_PATCHLEVEL=		1214
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.0/
VIM_SUBDIR=		vim80

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
