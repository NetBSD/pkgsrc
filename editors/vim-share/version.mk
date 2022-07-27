# $NetBSD: version.mk,v 1.138 2022/07/27 15:13:11 khorben Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		5172
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.2/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
