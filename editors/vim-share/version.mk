# $NetBSD: version.mk,v 1.114 2018/04/16 10:19:37 morr Exp $

VIM_VERSION=		8.0
VIM_PATCHLEVEL=		1722
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.0/
VIM_SUBDIR=		vim80

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
