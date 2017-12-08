# $NetBSD: version.mk,v 1.112 2017/12/08 20:12:43 bsiegert Exp $

VIM_VERSION=		8.0
VIM_PATCHLEVEL=		1379
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.0/
VIM_SUBDIR=		vim80

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
