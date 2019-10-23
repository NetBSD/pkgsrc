# $NetBSD: version.mk,v 1.125 2019/10/23 07:28:31 morr Exp $

VIM_VERSION=		8.1
VIM_PATCHLEVEL=		2200
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.1/
VIM_SUBDIR=		vim81

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
