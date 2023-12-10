# $NetBSD: version.mk,v 1.142.2.1 2023/12/10 17:09:35 bsiegert Exp $

VIM_VERSION=		9.0
VIM_PATCHLEVEL=		2122
# Changelog: see http://ftp.vim.org/pub/vim/patches/9.0/
VIM_SUBDIR=		vim90

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
