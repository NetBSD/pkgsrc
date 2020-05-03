# $NetBSD: version.mk,v 1.127 2020/05/03 13:14:21 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		0683
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.1/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
