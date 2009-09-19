# $NetBSD: Makefile,v 1.97 2009/09/19 07:46:12 ahoka Exp $
#

DISTNAME=	file-roller-2.26.3
PKGREVISION=	2
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/file-roller/2.26/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fileroller.sourceforge.net/
COMMENT=	Front-end to archiving programs like tar and zip
LICENSE=	gnu-gpl-v2

DEPENDS+=		gtar-base>=1.13.25:../../archivers/gtar-base
DEPENDS+=		unzip>=5.50nb2:../../archivers/unzip
DEPENDS+=		zip>=2.3nb2:../../archivers/zip

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS=		file-roller.schemas

BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.12.0
BUILDLINK_API_DEPENDS.gnome-vfs+=	gnome-vfs>=2.10.0
BUILDLINK_API_DEPENDS.gtk2+=		gtk2+>=2.10.0
BUILDLINK_API_DEPENDS.libglade+=	libglade>=2.4.0

# Force to use unzip from pkgsrc as other installed versions in path
# may be incompatible. (For example NetBSD 6.0's unzip)
#
SUBST_CLASSES+=		unzip
SUBST_STAGE.unzip=	pre-build
SUBST_MESSAGE.unzip=	Hardcoding unzip path
SUBST_FILES.unzip=	src/fr-command-zip.c
SUBST_SED.unzip=	-e 's|@@UNZIP_COMMAND@@|${LOCALBASE}/bin/unzip|'

# XXX force regen, bundled one doesn't fit
# see gnome bugzilla #587869
post-extract:
	${RM} ${WRKSRC}/src/fr-enum-types.c

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
#.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
