# $NetBSD: Makefile,v 1.50 2009/05/21 16:04:03 wiz Exp $

DISTNAME=	dasher-4.10.1
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dasher/4.10/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.inference.phy.cam.ac.uk/dasher/
COMMENT=	Easy typing without using keyboard
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		gnome2-1.5
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	${GCONF_SCHEMAS_DIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
# Needed for ftime(3).
LIBS+=			-lcompat
.endif

GCONF_SCHEMAS+=	dasher.schemas

post-build:
	cd ${WRKSRC}/Data && ../Src/Gtk2/generate-schema >dasher.schemas

post-install:
	${INSTALL_DATA} ${WRKSRC}/Data/dasher.schemas ${DESTDIR}${GCONF_SCHEMAS_DIR}

.include "../../audio/gnome-speech/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
