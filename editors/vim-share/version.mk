# $NetBSD: version.mk,v 1.146 2024/05/11 11:14:57 morr Exp $

VIM_VERSION=		9.1
VIM_PATCHLEVEL=		0407
# Changelog: see http://ftp.vim.org/pub/vim/patches/9.0/
VIM_SUBDIR=		vim91

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
