# $NetBSD: Makefile,v 1.4 2005/12/09 16:39:16 joerg Exp $

PKGNAME=	vim-lang-${VIM_VERSION}.${VIM_PATCHLEVEL}

.include "../../editors/vim-share/Makefile.common"

COMMENT=	Language files for the vim editor (vi clone)

DEPENDS+=	vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share

BUILD_USES_MSGFMT=	yes
BUILD_TARGET=	languages
INSTALL_TARGET=	install-languages

PLIST_SUBST+=	VIM_SUBDIR=${VIM_SUBDIR:Q}

BUILDLINK_DEPMETHOD.gettext-lib?=       build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
