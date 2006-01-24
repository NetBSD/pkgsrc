# $NetBSD: Makefile,v 1.6 2006/01/24 07:32:31 wiz Exp $
#

DISTNAME=		evince-0.4.0
PKGREVISION=		3
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/evince/0.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/evince/
COMMENT=		Document viewer for the GNOME Desktop

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_MSGFMT_PLURALS=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

GCONF2_SCHEMAS=		evince.schemas
GCONF2_SCHEMAS+=	evince-thumbnailer.schemas

# XXX fake for "configure" to allow build w/o a gs installed
# (avoid hard dependency on a specific version)
CONFIGURE_ARGS+=	--with-gs=${LOCALBASE}/bin/gs
pre-configure:
	${ECHO} "echo 8.51" >${BUILDLINK_DIR}/bin/gs
	${CHMOD} +x ${BUILDLINK_DIR}/bin/gs

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
