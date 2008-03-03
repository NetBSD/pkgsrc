# $NetBSD: Makefile,v 1.8 2008/03/03 17:45:34 jlam Exp $

PKGNAME=	${DISTNAME:S/-/-gtk-/}
PKGREVISION=	3
COMMENT=	Graphical monitor for distcc, the distributed C/C++ compiler

PKG_DESTDIR_SUPPORT=	user-destdir

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
		${DESTDIR}${PREFIX:Q}/bin/distccmon-gtk
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX:Q}/share/distcc
	${INSTALL_DATA} ${WRKSRC:Q}/gnome/distccmon-gnome-icon.png \
		${DESTDIR}${PREFIX:Q}/share/distcc/distccmon-gtk-icon.png
	${INSTALL_DATA} ${WRKSRC:Q}/gnome/distccmon-gnome.desktop \
		${DESTDIR}${PREFIX:Q}/share/distcc/distccmon-gtk.desktop

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
