# $NetBSD: Makefile,v 1.8 2002/08/25 18:38:59 jlam Exp $

PKGNAME=		freetype-lib-${FT_VERS}
COMMENT=		TrueType font rendering engine and library API

USE_BUILDLINK2=		# defined
CONFIGURE_ARGS+=	--without-x

.include "Makefile.common"

ALL_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "../../mk/bsd.pkg.mk"
