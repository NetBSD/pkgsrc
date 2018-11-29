# $NetBSD: version.mk,v 1.120 2018/11/29 08:55:10 morr Exp $

VIM_VERSION=		8.1
VIM_PATCHLEVEL=		0551
# Changelog: see http://ftp.vim.org/pub/vim/patches/8.1/
VIM_SUBDIR=		vim81

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
