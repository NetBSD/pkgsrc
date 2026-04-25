# $NetBSD: version.mk,v 1.163.2.4 2026/04/25 19:16:14 bsiegert Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0390
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
