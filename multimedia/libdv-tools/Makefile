# $NetBSD: Makefile,v 1.3 2006/04/06 06:22:25 reed Exp $

.include "../../multimedia/libdv/Makefile.common"

PKGNAME=		${DISTNAME:S/-/-tools-/}
PKGREVISION=		1

COMMENT+=		(standalone tools)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-gtk/--enable-gtk/g}

BUILD_DIRS=		${WRKSRC}/encodedv ${WRKSRC}/playdv
INSTALL_DIRS=		${WRKSRC}/encodedv ${WRKSRC}/playdv

BUILDLINK_API_DEPENDS.libdv+=	libdv>=0.104nb1

.include "../../devel/glib/buildlink3.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
