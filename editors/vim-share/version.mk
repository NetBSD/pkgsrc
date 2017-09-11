# $NetBSD: version.mk,v 1.107 2017/09/11 21:05:00 wiz Exp $

VIM_VERSION=		8.0
VIM_PATCHLEVEL=		1096
VIM_SUBDIR=		vim80

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
