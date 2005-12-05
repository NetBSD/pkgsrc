# $NetBSD: Makefile,v 1.6 2005/12/05 20:50:38 rillig Exp $

PKGNAME=	${DISTNAME:S/-/-gtk-/}
PKGREVISION=	1

COMMENT=	GTK frontend for free real-time 3D space simulator

DEPENDS+=	celestia-${CELESTIA_VERS}*:../../misc/celestia

CONFIGURE_ARGS+=	--with-gtk

BUILD_DIRS=	${WRKSRC}/src

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/celestia/celestia ${PREFIX}/bin/gtkcelestia

.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../misc/celestia/Makefile.common"

.include "../../mk/bsd.pkg.mk"
