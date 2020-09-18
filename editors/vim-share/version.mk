# $NetBSD: version.mk,v 1.129 2020/09/18 23:55:51 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		1709
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.1/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
