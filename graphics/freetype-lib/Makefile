# $NetBSD: Makefile,v 1.1.1.1 2000/05/01 06:02:23 jlam Exp $

PKGNAME=		freetype-lib-${FT_VERS}

DEPENDS+=		gettext-0.10.*:../../devel/gettext

CONFIGURE_ARGS+=	--without-x

ALL_TARGET=		ttlib ttpo
INSTALL_TARGET=		install-ttlib install-ttpo

.include "../../graphics/freetype-lib/Makefile.common"
