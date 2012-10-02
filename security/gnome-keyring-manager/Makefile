# $NetBSD: Makefile,v 1.37 2012/10/02 17:11:53 tron Exp $
#

DISTNAME=	gnome-keyring-manager-2.20.0
PKGREVISION=	18
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-keyring-manager/2.20/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnomesupport.org/wiki/index.php/GNOME_Keyring_Manager_Wiki
COMMENT=	GNOME password and secret manager

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config

GCONF_SCHEMAS=		gnome-keyring-manager.schemas

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
