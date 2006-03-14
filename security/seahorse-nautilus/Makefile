# $NetBSD: Makefile,v 1.1.1.1 2006/03/14 15:02:38 drochner Exp $

DISTNAME=	seahorse-0.8.1
PKGNAME=	seahorse-nautilus-0.8.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/seahorse/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seahorse.sourceforge.net/
COMMENT=	Seahorse plugin for nautilus

PATCHDIR=	${.CURDIR}/../seahorse/patches
DISTINFO_FILE=	${.CURDIR}/../seahorse/distinfo
BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
USE_MSGFMT_PLURALS=	yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--disable-gedit

BUILDLINK_DEPENDS.gpgme+=	gpgme>=1.0.1nb2

BUILD_DIRS=	plugins/nautilus-ext
INSTALL_DIRS=	plugins/nautilus-ext

.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
