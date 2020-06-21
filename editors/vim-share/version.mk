# $NetBSD: version.mk,v 1.128 2020/06/21 19:53:01 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		1033
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.1/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
