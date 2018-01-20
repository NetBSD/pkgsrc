# $NetBSD: version.mk,v 1.113 2018/01/20 12:19:09 morr Exp $

VIM_VERSION=		8.0
VIM_PATCHLEVEL=		1428
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.0/
VIM_SUBDIR=		vim80

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
