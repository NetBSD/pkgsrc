# $NetBSD: version.mk,v 1.158.2.1 2026/02/07 22:12:29 maya Exp $

VIM_VERSION=		9.1
VIM_PATCHLEVEL=		2132
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim91

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
