# $NetBSD: Makefile,v 1.1.1.1 2000/05/01 06:03:36 jlam Exp $

PKGNAME=		freetype-utils-${FT_VERS}

DEPENDS+=		freetype-lib-${FT_VERS}:../../graphics/freetype-lib

USE_X11=		# defined
CONFIGURE_ARGS+=	--with-x

ALL_TARGET=		tttest
INSTALL_TARGET=		install-tttest

pre-build:
	${TOUCH} ${WRKSRC}/lib/libttf.la

.include "../../graphics/freetype-lib/Makefile.common"
