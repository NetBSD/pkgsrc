# $NetBSD: Makefile,v 1.1.1.1 2004/11/10 16:40:56 adam Exp $

PKGNAME=	${DISTNAME:S/-/-gtk-/}

COMMENT=	GNOME frontend for free real-time 3D space simulator

DEPENDS=	celestia-${CELESTIA_VERS}*:../../misc/celestia

CONFIGURE_ARGS+=	--with-gtk

BUILD_DIRS=	${WRKSRC}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/celestia/celestia ${PREFIX}/bin/gtkcelestia

.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../misc/celestia/Makefile.common"
