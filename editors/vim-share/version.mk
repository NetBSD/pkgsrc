# $NetBSD: version.mk,v 1.123 2019/06/17 22:18:02 morr Exp $

VIM_VERSION=		8.1
VIM_PATCHLEVEL=		1566
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.1/
VIM_SUBDIR=		vim81

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
