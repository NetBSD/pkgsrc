# $NetBSD: Makefile,v 1.2 2000/08/12 06:34:36 jlam Exp $

PKGNAME=		${DISTNAME:S/-/-share-/}

BUILD_DEPENDS+=		${LOCALBASE}/include/libintl.h:../../devel/gettext

CONFIGURE_ARGS+=	--disable-server
CONFIGURE_ARGS+=	--enable-client=no
CPPFLAGS+=		-I${LOCALBASE}/include		# libintl.h

.include "../../games/freeciv-share/Makefile.common"
