# $NetBSD: Makefile,v 1.161 2022/06/28 11:31:47 wiz Exp $
#

DISTNAME=	libgnomeui-2.24.5
PKGREVISION=	57
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomeui/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Core GNOME2 graphical libraries
LICENSE=	gnu-lgpl-v2

CONFLICTS+=		gnome-libs<=1.4.2nb1

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt perl pkg-config intltool
USE_LIBTOOL=		yes

PKGCONFIG_BASE=		${WRKSRC}/libgnomeui/libgnomeui-2.0.pc
PKGCONFIG_OVERRIDE=	${PKGCONFIG_BASE}.in

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[6-9]*) || !empty(CC_VERSION:Mgcc-1[0-9].*) || !empty(PKGSRC_COMPILER:Mclang)
SUBST_CLASSES.SunOS+=	xopen
SUBST_STAGE.xopen=	pre-configure
SUBST_FILES.xopen=	libgnomeui/gnome-file-entry.c libgnomeui/gnome-client.c
SUBST_FILES.xopen+=	libgnomeui/gnome-dateedit.c
SUBST_SED.xopen=	-e '/_XOPEN_SOURCE/s/500/600/'
SUBST_SED.xopen+=	-e '/_XOPEN_SOURCE$$/s/$$/ 600/'
.endif

# Needed because part of the pc files doesn't get filled in till after
# configure does its pass
post-configure:
	${SED} ${PKGCONFIG_OVERRIDE_SED} < ${PKGCONFIG_BASE} > \
		${PKGCONFIG_BASE}.tmp
	${MV} ${PKGCONFIG_BASE}.tmp ${PKGCONFIG_BASE}

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2=		glib2>=2.15.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
BUILDLINK_API_DEPENDS.libbonoboui=	libbonoboui>=2.13.1
.include "../../devel/libbonoboui/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnome=		libgnome>=2.16.0
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2=		gtk2+>=2.14.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
