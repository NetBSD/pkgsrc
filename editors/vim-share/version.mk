# $NetBSD: version.mk,v 1.140 2022/11/28 10:00:33 morr Exp $

VIM_VERSION=		9.0
VIM_PATCHLEVEL=		0960
# Changelog: see http://ftp.vim.org/pub/vim/patches/9.0/
VIM_SUBDIR=		vim90

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
