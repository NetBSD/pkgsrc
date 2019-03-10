# $NetBSD: version.mk,v 1.122 2019/03/10 18:45:45 morr Exp $

VIM_VERSION=		8.1
VIM_PATCHLEVEL=		1004
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.1/
VIM_SUBDIR=		vim81

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
