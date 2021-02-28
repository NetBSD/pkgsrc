# $NetBSD: version.mk,v 1.132 2021/02/28 00:23:37 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		2557
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.2/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
