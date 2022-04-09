# $NetBSD: version.mk,v 1.137 2022/04/09 15:22:20 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		4721
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.2/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
