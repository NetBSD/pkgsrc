# $NetBSD: version.mk,v 1.108 2017/09/18 23:27:01 wiz Exp $

VIM_VERSION=		8.0
VIM_PATCHLEVEL=		1096
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.0/
VIM_SUBDIR=		vim80

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
