# $NetBSD: version.mk,v 1.136 2022/01/25 13:46:33 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		4214
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.2/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
