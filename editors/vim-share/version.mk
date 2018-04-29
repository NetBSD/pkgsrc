# $NetBSD: version.mk,v 1.115 2018/04/29 05:50:39 wiz Exp $

VIM_VERSION=		8.0
VIM_PATCHLEVEL=		1772
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.0/
VIM_SUBDIR=		vim80

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
