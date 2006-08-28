# $NetBSD: Makefile,v 1.6 2006/08/28 09:03:40 jmmv Exp $
#

DISTNAME=	gnome-keyring-manager-2.14.0
PKGREVISION=	2
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-keyring-manager/2.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://gnomesupport.org/wiki/index.php/GNOME_Keyring_Manager_Wiki
COMMENT=	GNOME password and secret manager

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.6
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config

GCONF2_SCHEMAS=		gnome-keyring-manager.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
