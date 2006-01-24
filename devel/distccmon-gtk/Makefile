# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:01 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-gtk-/}
PKGREVISION=	1
COMMENT=	Graphical monitor for distcc, the distributed C/C++ compiler

.include "../../devel/distcc/Makefile.common"

CONFIGURE_ARGS+=	--with-gtk

SUBST_CLASSES+=		gtk
SUBST_STAGE.gtk=	post-patch
SUBST_FILES.gtk=	gnome/distccmon-gnome.desktop src/mon-gnome.c
SUBST_SED.gtk=		-e "s/distccmon-gnome/distccmon-gtk/g"
SUBST_MESSAGE.gtk=	"Renaming -gnome to -gtk."

BUILD_TARGET=		distccmon-gnome

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/distccmon-gnome \
		${PREFIX}/bin/distccmon-gtk
	${INSTALL_DATA_DIR} ${PREFIX}/share/distcc
	${INSTALL_DATA} ${WRKSRC}/gnome/distccmon-gnome-icon.png \
		${PREFIX}/share/distcc/distccmon-gtk-icon.png
	${INSTALL_DATA} ${WRKSRC}/gnome/distccmon-gnome.desktop \
		${PREFIX}/share/distcc/distccmon-gtk.desktop

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
