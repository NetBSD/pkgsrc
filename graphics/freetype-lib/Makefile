# $NetBSD: Makefile,v 1.7.2.1 2002/06/06 06:54:38 jlam Exp $

PKGNAME=		freetype-lib-${FT_VERS}
COMMENT=		TrueType font rendering engine and library API

USE_BUILDLINK2_ONLY=	# defined
CONFIGURE_ARGS+=	--without-x

.include "Makefile.common"

ALL_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "../../mk/bsd.pkg.mk"
