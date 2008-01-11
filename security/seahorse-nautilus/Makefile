# $NetBSD: Makefile,v 1.17 2008/01/11 13:56:56 drochner Exp $

DISTNAME=	seahorse-2.20.3
PKGNAME=	seahorse-nautilus-2.20.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/seahorse/2.20/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seahorse.sourceforge.net/
COMMENT=	Seahorse plugin for nautilus

PATCHDIR=	${.CURDIR}/../seahorse/patches
DISTINFO_FILE=	${.CURDIR}/../seahorse/distinfo

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake intltool msgfmt pkg-config
#autoconf
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--disable-gedit

BUILDLINK_API_DEPENDS.gpgme+=	gpgme>=1.0.1nb2

BUILD_DIRS=	plugins/nautilus-ext
INSTALL_DIRS=	plugins/nautilus-ext

.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
