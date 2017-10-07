# $NetBSD: version.mk,v 1.109 2017/10/07 12:32:23 morr Exp $

VIM_VERSION=		8.0
VIM_PATCHLEVEL=		1176
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.0/
VIM_SUBDIR=		vim80

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
