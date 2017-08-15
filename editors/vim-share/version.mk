# $NetBSD: version.mk,v 1.106 2017/08/15 21:00:11 wiz Exp $

VIM_VERSION=		8.0
VIM_PATCHLEVEL=		0921
VIM_SUBDIR=		vim80

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
