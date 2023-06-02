# $NetBSD: version.mk,v 1.141 2023/06/02 15:30:10 wiz Exp $

VIM_VERSION=		9.0
VIM_PATCHLEVEL=		1598
# Changelog: see http://ftp.vim.org/pub/vim/patches/9.0/
VIM_SUBDIR=		vim90

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
