# $NetBSD: Makefile,v 1.5 2011/04/22 13:44:16 obache Exp $

.include "../../multimedia/libdv/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-tools-/}
PKGREVISION=		1

COMMENT+=		(standalone tools)

USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--enable-gtk

BUILD_DIRS=		encodedv playdv
INSTALL_DIRS=		encodedv playdv

BUILDLINK_API_DEPENDS.libdv+=	libdv>=1.0.0

.include "../../devel/glib/buildlink3.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
