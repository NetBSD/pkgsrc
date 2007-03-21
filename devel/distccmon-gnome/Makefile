# $NetBSD: Makefile,v 1.12 2007/03/21 12:05:42 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}
COMMENT=	Graphical monitor for distcc, the distributed C/C++ compiler

.include "../../devel/distcc/Makefile.common"
PKGREVISION=	7

USE_TOOLS+=	pkg-config

CATEGORIES+=	gnome

CONFIGURE_ARGS+=	--with-gnome

BUILD_TARGET=		distccmon-gnome

CHECK_PORTABILITY_SKIP+=	contrib/redhat/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/distccmon-gnome ${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/distcc
	${INSTALL_DATA} ${WRKSRC:Q}/gnome/distccmon-gnome-icon.png \
		${PREFIX:Q}/share/distcc
	${INSTALL_DATA} ${WRKSRC:Q}/gnome/distccmon-gnome.desktop \
		${PREFIX:Q}/share/distcc

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
