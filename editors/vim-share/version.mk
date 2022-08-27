# $NetBSD: version.mk,v 1.137.2.1 2022/08/27 15:35:48 spz Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		5172
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.2/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
