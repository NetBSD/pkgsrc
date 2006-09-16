# $NetBSD: Makefile,v 1.7 2006/09/16 12:20:40 jmmv Exp $

DISTNAME=	seahorse-0.8.1
PKGNAME=	seahorse-gedit-0.8.1
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/seahorse/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seahorse.sourceforge.net/
COMMENT=	Seahorse plugin for gedit

PATCHDIR=	${.CURDIR}/../seahorse/patches
DISTINFO_FILE=	${.CURDIR}/../seahorse/distinfo

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--disable-nautilus

GCONF2_SCHEMAS= 	seahorse-gedit.schemas

BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=1.0.1nb2

BUILD_DIRS=	plugins/gedit
INSTALL_DIRS=	plugins/gedit

.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../security/seahorse/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../editors/gedit/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
