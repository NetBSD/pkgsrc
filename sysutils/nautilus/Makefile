# $NetBSD: Makefile,v 1.1.1.1 2003/04/27 02:06:56 rh Exp $
#

DISTNAME=		nautilus-2.2.3.1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/nautilus/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/projects/nautilus/
COMMENT=		Nautilus file manager for GNOME2

USE_PKGLOCALEDIR=	yes
USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libnautilus/libnautilus.pc.in

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS+=	apps_nautilus_preferences.schemas

pre-build:
	for d in libnautilus libnautilus-adapter libnautilus-private src ; \
	do								\
		cd ${WRKSRC}/$$d &&					\
		for x in *.idl ; do					\
			${PREFIX}/bin/orbit-idl-2			\
			    -I${LOCALBASE}/share/idl/bonobo-2.0		\
			    -I${LOCALBASE}/share/idl/bonobo-activation-2.0 \
			    -I..					\
			    -D__nautilus_view_component_COMPILATION $$x ; \
			${TOUCH} `${ECHO} $$x | ${SED} s/\.idl/_idl_stamp/\
			    | ${SED} s/-/_/g` ;				\
		done ;							\
	done

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/eel2/buildlink2.mk"
.include "../../graphics/imlib2/buildlink2.mk"
.include "../../graphics/librsvg2/buildlink2.mk"
.include "../../sysutils/fam/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
