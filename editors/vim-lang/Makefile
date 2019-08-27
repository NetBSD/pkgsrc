# $NetBSD: Makefile,v 1.20 2019/08/27 09:26:02 maya Exp $

PKGNAME=	vim-lang-${VIM_VERSION}.${VIM_PATCHLEVEL}
PKGREVISION=	1

.include "../../editors/vim-share/Makefile.common"

COMMENT=	Language files for the vim editor (vi clone)

DEPENDS+=	vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}{,nb*}:../../editors/vim-share

USE_TOOLS+=	msgfmt
BUILD_TARGET=	languages
INSTALL_TARGET=	install-languages

PLIST_SUBST+=	VIM_SUBDIR=${VIM_SUBDIR}

BUILDLINK_DEPMETHOD.gettext-lib?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
