# $NetBSD: version.mk,v 1.135 2022/01/10 20:53:32 morr Exp $

VIM_VERSION=		8.2
VIM_PATCHLEVEL=		3899
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.2/
VIM_SUBDIR=		vim82

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
