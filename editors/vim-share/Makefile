# $NetBSD: Makefile,v 1.7 2001/10/04 10:18:12 martti Exp $

.include		"Makefile.common"

PKGNAME=		vim-share-${VIM_VERSION}

COMMENT=		Data files for the vim editor (vi clone)

CONFIGURE_ARGS+=	--disable-gui

INSTALL_TARGET=		installruntime installmacros installtutor installtools

PLIST_SUBST+=		VIM_SUBDIR="vim60"

do-build:
	@cd ${WRKSRC}/xxd && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

.include "../../mk/bsd.pkg.mk"
