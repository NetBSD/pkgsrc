# $NetBSD: Makefile,v 1.25 2006/11/26 09:02:20 martti Exp $

PKGNAME=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}
#PKGREVISION=		1

COMMENT=		Data files for the vim editor (vi clone)

.include		"Makefile.common"

CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--without-x

BUILD_TARGET=		vim
INSTALL_TARGET=		installruntime installmacros installtutor installtools
USE_TOOLS+=		awk
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} TOOLS_AWK=${TOOLS_AWK:Q} TOOLS_SETENV=${TOOLS_SETENV:Q}

PLIST_SUBST+=		VIM_SUBDIR=${VIM_SUBDIR:Q}

.include "../../mk/bsd.pkg.mk"
