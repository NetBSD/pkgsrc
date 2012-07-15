# $NetBSD: Makefile,v 1.116 2012/07/15 08:22:46 wiz Exp $
#

DISTNAME=	file-roller-2.32.2
PKGREVISION=	5
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/file-roller/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fileroller.sourceforge.net/
COMMENT=	Front-end to archiving programs like tar and zip
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake gtar:run intltool msgfmt perl pkg-config unzip:run
USE_TOOLS+=		zip:run
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS=		file-roller.schemas

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.12.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.10.0

# Force unzip from pkgsrc on NetBSD
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.unzip=
.endif

SUBST_CLASSES+=		unzip
SUBST_STAGE.unzip=	pre-build
SUBST_MESSAGE.unzip=	Hardcoding unzip path
SUBST_FILES.unzip=	src/fr-command-zip.c
SUBST_SED.unzip=	-e 's|@@UNZIP_COMMAND@@|${TOOLS_PATH.unzip}|'

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
