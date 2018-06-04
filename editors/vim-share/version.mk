# $NetBSD: version.mk,v 1.116 2018/06/04 09:05:00 morr Exp $

VIM_VERSION=		8.1
VIM_PATCHLEVEL=		0031
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.0/
VIM_SUBDIR=		vim81

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
