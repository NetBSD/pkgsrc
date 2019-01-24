# $NetBSD: version.mk,v 1.121 2019/01/24 11:17:37 morr Exp $

VIM_VERSION=		8.1
VIM_PATCHLEVEL=		0800
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.1/
VIM_SUBDIR=		vim81

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
