# $NetBSD: version.mk,v 1.131 2020/12/11 18:06:25 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		2127
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.2/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
