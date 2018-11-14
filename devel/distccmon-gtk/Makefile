# $NetBSD: Makefile,v 1.41 2018/11/14 22:21:14 kleink Exp $

PKGNAME=	${DISTNAME:S/-/-gtk-/}
PKGREVISION=	2
COMMENT=	Graphical monitor for distcc, the distributed C/C++ compiler

.include "../../devel/distcc/Makefile.common"

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-gtk

SUBST_CLASSES+=		gtk
SUBST_STAGE.gtk=	pre-configure
SUBST_FILES.gtk=	gnome/distccmon-gnome.desktop src/mon-gnome.c
SUBST_SED.gtk=		-e "s/distccmon-gnome/distccmon-gtk/g"
SUBST_MESSAGE.gtk=	Renaming -gnome to -gtk.

BUILD_TARGET=		distccmon-gnome
INSTALLATION_DIRS+=	share/distcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/distccmon-gnome \
		${DESTDIR}${PREFIX}/bin/distccmon-gtk
	${INSTALL_DATA} ${WRKSRC}/gnome/distccmon-gnome-icon.png \
		${DESTDIR}${PREFIX}/share/distcc/distccmon-gtk-icon.png
	${INSTALL_DATA} ${WRKSRC}/gnome/distccmon-gnome.desktop \
		${DESTDIR}${PREFIX}/share/distcc/distccmon-gtk.desktop

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
