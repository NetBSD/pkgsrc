# $NetBSD: Makefile,v 1.2 2005/08/29 09:52:45 drochner Exp $
#

DISTNAME=		evince-0.3.2
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/evince/0.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/projects/evince/
COMMENT=		Document viewer

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
USE_MSGFMT_PLURALS=	yes

CONFIGURE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"
MAKE_ENV+=		GCONF_SCHEMA_FILE_DIR="${PREFIX}/share/gconf/schemas/"

GCONF2_SCHEMAS+=	evince-thumbnailer.schemas
GCONF2_SCHEMAS+=	evince.schemas

# XXX fake for "configure" to allow build w/o a gs installed
# (avoid hard dependency on a specific version)
CONFIGURE_ARGS+=	--with-gs=${LOCALBASE}/bin/gs
pre-configure:
	${ECHO} "echo 8.51" >${BUILDLINK_DIR}/bin/gs
	${CHMOD} +x ${BUILDLINK_DIR}/bin/gs

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
