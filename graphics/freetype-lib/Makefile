# $NetBSD: Makefile,v 1.4 2001/03/16 13:28:38 wiz Exp $

PKGNAME=		freetype-lib-${FT_VERS}

COMMENT=		TrueType font rendering engine and library API

CONFIGURE_ARGS+=	--without-x

ALL_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

pre-build:
	@if ${PKG_INFO} -qe 'freetype-lib<${FT_VERS}'; then		\
		${ECHO} "**** An older version of freetype-lib is installed";	\
		${ECHO} "**** ${PKGNAME} cannot be built with it installed."; \
		${ECHO} "**** Please delete it before building";	\
		${ECHO} "**** or use \"${MAKE} update\".";		\
		${FALSE};						\
	fi

.include "../../graphics/freetype-lib/Makefile.common"
