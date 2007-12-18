# $NetBSD: Makefile,v 1.27 2007/12/18 08:15:03 martti Exp $

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
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} TOOLS_AWK=${TOOLS_AWK} TOOLS_SETENV=${TOOLS_SETENV}

PLIST_SUBST+=		VIM_SUBDIR=${VIM_SUBDIR}

.include "../../mk/bsd.pkg.mk"
