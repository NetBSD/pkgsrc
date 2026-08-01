# $NetBSD: version.mk,v 1.175.2.2 2026/08/01 19:56:25 maya Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0859
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s" v<old_version>...HEAD
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
