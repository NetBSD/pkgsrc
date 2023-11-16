# $NetBSD: version.mk,v 1.143 2023/11/16 09:54:10 wiz Exp $

VIM_VERSION=		9.0
VIM_PATCHLEVEL=		2105
# Changelog: see http://ftp.vim.org/pub/vim/patches/9.0/
VIM_SUBDIR=		vim90

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
