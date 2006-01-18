# $NetBSD: Makefile,v 1.3 2006/01/18 13:04:52 ghen Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}
COMMENT=	Graphical monitor for distcc, the distributed C/C++ compiler

.include "../../devel/distcc/Makefile.common"
PKGREVISION=	1

CATEGORIES+=	gnome

CONFIGURE_ARGS+=	--with-gnome

BUILD_TARGET=		distccmon-gnome

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/distccmon-gnome ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/distcc
	${INSTALL_DATA} ${WRKSRC}/gnome/distccmon-gnome-icon.png \
		${PREFIX}/share/distcc
	${INSTALL_DATA} ${WRKSRC}/gnome/distccmon-gnome.desktop \
		${PREFIX}/share/distcc

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
