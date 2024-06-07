# $NetBSD: version.mk,v 1.145.4.1 2024/06/07 13:35:53 bsiegert Exp $

VIM_VERSION=		9.1
VIM_PATCHLEVEL=		0407
# Changelog: see http://ftp.vim.org/pub/vim/patches/9.0/
VIM_SUBDIR=		vim91

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
