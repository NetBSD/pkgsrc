# $NetBSD: version.mk,v 1.133 2021/04/23 06:31:35 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		2800
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.2/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
