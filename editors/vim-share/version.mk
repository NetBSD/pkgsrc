# $NetBSD: version.mk,v 1.146.2.2 2024/08/28 15:17:16 bsiegert Exp $

VIM_VERSION=		9.1
VIM_PATCHLEVEL=		0698
# Changelog: see https://github.com/vim/vim/commits/master/ or
# with git clone: $ git log --pretty=format:"- %s"
VIM_SUBDIR=		vim91

PRINT_PLIST_AWK+=	{ gsub(/${VIM_SUBDIR}/, "$${VIM_SUBDIR}"); print; next; }
