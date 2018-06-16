# $NetBSD: version.mk,v 1.117 2018/06/16 22:46:43 morr Exp $

VIM_VERSION=		8.1
VIM_PATCHLEVEL=		0061
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.0/
VIM_SUBDIR=		vim81

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
