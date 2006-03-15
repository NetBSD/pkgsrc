# $NetBSD: Makefile,v 1.1.1.1 2006/03/15 19:27:05 drochner Exp $
#

DISTNAME=		evince-0.4.0
PKGNAME=		evince-nautilus-0.4.0
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/evince/0.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/evince/
COMMENT=		Document viewer for the GNOME Desktop

#PATCHDIR=		${.CURDIR}/../evince/patches
DISTINFO_FILE=		${.CURDIR}/../evince/distinfo

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_MSGFMT_PLURALS=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

BUILD_DIRS=		libbackend lib properties
INSTALL_DIRS=		properties

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
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
