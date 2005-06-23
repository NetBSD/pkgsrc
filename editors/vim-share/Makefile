# $NetBSD: Makefile,v 1.15 2005/06/23 17:49:40 kristerw Exp $

PKGNAME=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}
PKGREVISION=		2

COMMENT=		Data files for the vim editor (vi clone)

.include		"Makefile.common"

CONFIGURE_ARGS+=	--disable-gui

INSTALL_TARGET=		installruntime installmacros installtutor installtools
USE_TOOLS+=		awk
INSTALL_MAKE_FLAGS+=	TOOLS_AWK="${TOOLS_AWK}"

PLIST_SUBST+=		VIM_SUBDIR="${VIM_SUBDIR}"

do-build:
	@cd ${WRKSRC}/xxd && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

.include "../../mk/bsd.pkg.mk"
