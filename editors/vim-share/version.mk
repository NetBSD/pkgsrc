# $NetBSD: version.mk,v 1.139 2022/08/28 19:49:13 morr Exp $

VIM_VERSION=		9.0
VIM_PATCHLEVEL=		0305
# Changelog: see http://ftp.vim.org/pub/vim/patches/9.0/
VIM_SUBDIR=		vim90

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
