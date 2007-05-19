# $NetBSD: Makefile,v 1.26 2007/05/19 00:13:00 heinz Exp $

PKGNAME=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}
#PKGREVISION=		1

COMMENT=		Data files for the vim editor (vi clone)

PKG_DESTDIR_SUPPORT=	user-destdir

.include		"Makefile.common"

CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--without-x

BUILD_TARGET=		vim
INSTALL_TARGET=		installruntime installmacros installtutor installtools
USE_TOOLS+=		awk
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} TOOLS_AWK=${TOOLS_AWK:Q} TOOLS_SETENV=${TOOLS_SETENV:Q}

PLIST_SUBST+=		VIM_SUBDIR=${VIM_SUBDIR:Q}

.include "../../mk/bsd.pkg.mk"
