# $NetBSD: Makefile,v 1.23 2004/02/11 22:56:23 xtraeme Exp $
#

DISTNAME=		nautilus-2.4.2
PKGREVISION=		3
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/nautilus/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/nautilus/
COMMENT=		Nautilus file manager for GNOME2

USE_PKGLOCALEDIR=	yes
USE_BUILDLINK3=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libnautilus/libnautilus.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

GCONF2_SCHEMAS=		apps_nautilus_preferences.schemas

OWN_DIRS=		${PKG_SYSCONFDIR}/X11/serverconfig
OWN_DIRS+=		${PKG_SYSCONFDIR}/X11/starthere
OWN_DIRS+=		${PKG_SYSCONFDIR}/X11/sysconfig
EGDIR=			${PREFIX}/share/examples/nautilus
CONF_FILES=
.for conffile in	X11/serverconfig/.directory \
			X11/starthere/.directory \
			X11/starthere/applications.desktop \
			X11/starthere/preferences.desktop \
			X11/starthere/serverconfig.desktop \
			X11/starthere/sysconfig.desktop \
			X11/sysconfig/.directory
CONF_FILES+=		${EGDIR}/${conffile} ${PKG_SYSCONFDIR}/${conffile}
.endfor
.undef conffile

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
