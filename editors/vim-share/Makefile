# $NetBSD: Makefile,v 1.51 2019/08/11 13:20:57 wiz Exp $

PKGNAME=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}
PKGREVISION=		1
COMMENT=		Data files for the vim editor (vi clone)

.include		"Makefile.common"

CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--without-x

BUILD_TARGET=		vim
INSTALL_TARGET=		installruntime installmacros installtutor installtools
USE_TOOLS+=		awk
INSTALL_MAKE_FLAGS+=	${MAKE_FLAGS} TOOLS_AWK=${TOOLS_AWK} TOOLS_SETENV=${TOOLS_SETENV}

PLIST_SUBST+=		VIM_SUBDIR=${VIM_SUBDIR}

CHECK_INTERPRETER_SKIP+=	share/vim/${VIM_SUBDIR}/doc/*.pl
CHECK_INTERPRETER_SKIP+=	share/vim/${VIM_SUBDIR}/tools/*.pl
CHECK_INTERPRETER_SKIP+=	share/vim/${VIM_SUBDIR}/tools/*.py

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
