# $NetBSD: Makefile,v 1.7 2006/10/24 17:33:59 rillig Exp $

PKGNAME=	${DISTNAME:S/-/-gtk-/}
PKGREVISION=	3
COMMENT=	Graphical monitor for distcc, the distributed C/C++ compiler

.include "../../devel/distcc/Makefile.common"

CONFIGURE_ARGS+=	--with-gtk

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		gtk
SUBST_STAGE.gtk=	post-patch
SUBST_FILES.gtk=	gnome/distccmon-gnome.desktop src/mon-gnome.c
SUBST_SED.gtk=		-e "s/distccmon-gnome/distccmon-gtk/g"
SUBST_MESSAGE.gtk=	Renaming -gnome to -gtk.

BUILD_TARGET=		distccmon-gnome

CHECK_PORTABILITY_SKIP+=	contrib/redhat/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/distccmon-gnome \
		${PREFIX:Q}/bin/distccmon-gtk
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/distcc
	${INSTALL_DATA} ${WRKSRC:Q}/gnome/distccmon-gnome-icon.png \
		${PREFIX:Q}/share/distcc/distccmon-gtk-icon.png
	${INSTALL_DATA} ${WRKSRC:Q}/gnome/distccmon-gnome.desktop \
		${PREFIX:Q}/share/distcc/distccmon-gtk.desktop

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
