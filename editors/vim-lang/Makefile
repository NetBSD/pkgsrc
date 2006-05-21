# $NetBSD: Makefile,v 1.10 2006/05/21 13:32:27 martti Exp $

PKGNAME=	vim-lang-${VIM_VERSION}.${VIM_PATCHLEVEL}
#PKGREVISION=	1

.include "../../editors/vim-share/Makefile.common"

COMMENT=	Language files for the vim editor (vi clone)

DEPENDS+=	vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share

USE_TOOLS+=	msgfmt
BUILD_TARGET=	languages
INSTALL_TARGET=	install-languages

PLIST_SUBST+=	VIM_SUBDIR=${VIM_SUBDIR:Q}

BUILDLINK_DEPMETHOD.gettext-lib?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
