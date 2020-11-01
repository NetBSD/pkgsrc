# $NetBSD: version.mk,v 1.130 2020/11/01 14:53:00 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		1933
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.2/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
