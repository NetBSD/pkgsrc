# $NetBSD: Makefile,v 1.2 2001/02/16 15:22:19 wiz Exp $

PKGNAME=		freetype-utils-${FT_VERS}

COMMENT=		Utilities for manipulating TrueType fonts

DEPENDS+=		freetype-lib-${FT_VERS}:../../graphics/freetype-lib

USE_X11=		# defined
CONFIGURE_ARGS+=	--with-x

ALL_TARGET=		tttest
INSTALL_TARGET=		install-tttest

pre-build:
	${TOUCH} ${WRKSRC}/lib/libttf.la

.include "../../graphics/freetype-lib/Makefile.common"
