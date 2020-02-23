# $NetBSD: version.mk,v 1.126 2020/02/23 10:39:33 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		0303
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.1/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
