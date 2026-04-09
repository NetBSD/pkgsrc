# $NetBSD: version.mk,v 1.163.2.1 2026/04/09 18:01:29 maya Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0315
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
