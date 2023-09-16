# $NetBSD: version.mk,v 1.142 2023/09/16 12:21:18 rhialto Exp $

VIM_VERSION=		9.0
VIM_PATCHLEVEL=		1900
# Changelog: see http://ftp.vim.org/pub/vim/patches/9.0/
VIM_SUBDIR=		vim90

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
