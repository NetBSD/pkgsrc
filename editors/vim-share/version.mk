# $NetBSD: version.mk,v 1.145 2023/11/23 19:10:01 morr Exp $

VIM_VERSION=		9.0
VIM_PATCHLEVEL=		2122
# Changelog: see http://ftp.vim.org/pub/vim/patches/9.0/
VIM_SUBDIR=		vim90

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
