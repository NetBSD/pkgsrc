# $NetBSD: Makefile,v 1.11 2005/01/25 13:48:54 jmmv Exp $

PKGNAME=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}

COMMENT=		Data files for the vim editor (vi clone)

.include		"Makefile.common"

CONFIGURE_ARGS+=	--disable-gui

INSTALL_TARGET=		installruntime installmacros installtutor installtools

PLIST_SUBST+=		VIM_SUBDIR="vim63"

do-build:
	@cd ${WRKSRC}/xxd && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

.include "../../mk/bsd.pkg.mk"
