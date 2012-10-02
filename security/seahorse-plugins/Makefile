# $NetBSD: Makefile,v 1.33 2012/10/02 17:11:55 tron Exp $

DISTNAME=	seahorse-plugins-2.30.1
PKGREVISION=	17
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/seahorse-plugins/2.30/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/seahorse/
COMMENT=	Plugins for the GnuPG front end and bonobo component for GNOME
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
CONFIGURE_ENV+=		ac_cv_path_GNUPG=${GPGME_GPG}

GCONF_SCHEMAS=		seahorse-gedit.schemas
GCONF_SCHEMAS+=		seahorse-plugins.schemas

.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../editors/gedit/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/seahorse/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
# doesn't suffice, configure says:
# checking whether we have a gtk 2 gecko build... configure: error: This program needs a gtk 2 gecko build
#.include "../../devel/xulrunner/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
