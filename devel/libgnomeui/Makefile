# $NetBSD: Makefile,v 1.125 2014/05/05 00:47:45 ryoon Exp $
#

DISTNAME=	libgnomeui-2.24.5
PKGREVISION=	26
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomeui/2.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Core GNOME2 graphical libraries
LICENSE=	gnu-lgpl-v2

CONFLICTS+=		gnome-libs<=1.4.2nb1

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt perl pkg-config intltool
USE_LIBTOOL=		yes

PKGCONFIG_BASE=		${WRKSRC}/libgnomeui/libgnomeui-2.0.pc
PKGCONFIG_OVERRIDE=	${PKGCONFIG_BASE}.in

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
