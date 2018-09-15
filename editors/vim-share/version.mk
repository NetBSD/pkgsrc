# $NetBSD: version.mk,v 1.119 2018/09/15 12:36:41 bsiegert Exp $

VIM_VERSION=		8.1
VIM_PATCHLEVEL=		0390
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.1/
VIM_SUBDIR=		vim81

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
