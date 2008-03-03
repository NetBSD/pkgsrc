# $NetBSD: Makefile,v 1.16 2008/03/03 17:45:34 jlam Exp $

PKGNAME=	${DISTNAME:S/-/-gnome-/}
PKGREVISION=	10
COMMENT=	Graphical monitor for distcc, the distributed C/C++ compiler

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/distcc/Makefile.common"

USE_TOOLS+=	pkg-config

CATEGORIES+=	gnome

CONFIGURE_ARGS+=	--with-gnome

BUILD_TARGET=		distccmon-gnome

CHECK_PORTABILITY_SKIP+=	contrib/redhat/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/distccmon-gnome ${DESTDIR}${PREFIX:Q}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX:Q}/share/distcc
	${INSTALL_DATA} ${WRKSRC:Q}/gnome/distccmon-gnome-icon.png \
		${DESTDIR}${PREFIX:Q}/share/distcc
	${INSTALL_DATA} ${WRKSRC:Q}/gnome/distccmon-gnome.desktop \
		${DESTDIR}${PREFIX:Q}/share/distcc

.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
