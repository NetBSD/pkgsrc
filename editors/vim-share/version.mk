# $NetBSD: version.mk,v 1.163.2.5 2026/05/12 19:22:00 bsiegert Exp $

VIM_VERSION=		9.2
VIM_PATCHLEVEL=		0461
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim92

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
