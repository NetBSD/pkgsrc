# $NetBSD: Makefile,v 1.19 2006/03/02 10:41:41 martti Exp $

PKGNAME=		vim-share-${VIM_VERSION}.${VIM_PATCHLEVEL}
PKGREVISION=		1

COMMENT=		Data files for the vim editor (vi clone)

.include		"Makefile.common"

CONFIGURE_ARGS+=	--disable-gui

INSTALL_TARGET=		installruntime installmacros installtutor installtools
USE_TOOLS+=		awk
INSTALL_MAKE_FLAGS+=	TOOLS_AWK=${TOOLS_AWK:Q}

PLIST_SUBST+=		VIM_SUBDIR=${VIM_SUBDIR:Q}

do-build:
	@cd ${WRKSRC:Q}/xxd && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

.include "../../mk/bsd.pkg.mk"
