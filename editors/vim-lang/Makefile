# $NetBSD: Makefile,v 1.3 2005/12/05 20:50:10 rillig Exp $

PKGNAME=	vim-lang-${VIM_VERSION}.${VIM_PATCHLEVEL}

.include "../../editors/vim-share/Makefile.common"

COMMENT=	Language files for the vim editor (vi clone)

DEPENDS+=	vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share

BUILD_TARGET=	languages
INSTALL_TARGET=	install-languages

PLIST_SUBST+=	VIM_SUBDIR=${VIM_SUBDIR:Q}

.include "../../mk/bsd.pkg.mk"
