# $NetBSD: Makefile,v 1.10 2004/06/21 08:23:48 martti Exp $

.include		"Makefile.common"

PKGNAME=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}

COMMENT=		Data files for the vim editor (vi clone)

CONFIGURE_ARGS+=	--disable-gui

INSTALL_TARGET=		installruntime installmacros installtutor installtools

PLIST_SUBST+=		VIM_SUBDIR="vim63"

do-build:
	@cd ${WRKSRC}/xxd && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

.include "../../mk/bsd.pkg.mk"
