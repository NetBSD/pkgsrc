# $NetBSD: Makefile,v 1.2 2005/07/19 10:18:59 grant Exp $

PKGNAME=	vim-lang-${VIM_VERSION}.${VIM_PATCHLEVEL}

.include	"../vim-share/Makefile.common"

COMMENT=	Language files for the vim editor (vi clone)

DEPENDS+=	vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share

BUILD_TARGET=	languages
INSTALL_TARGET=	install-languages

PLIST_SUBST+=	VIM_SUBDIR="${VIM_SUBDIR}"

.include "../../mk/bsd.pkg.mk"
