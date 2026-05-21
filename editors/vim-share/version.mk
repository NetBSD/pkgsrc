# $NetBSD: version.mk,v 1.163.2.6 2026/05/21 02:27:36 maya Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0496
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s" v<old_version>...HEAD
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
