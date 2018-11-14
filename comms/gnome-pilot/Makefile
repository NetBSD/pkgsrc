# $NetBSD: Makefile,v 1.120 2018/11/14 22:21:10 kleink Exp $

DISTNAME=		gnome-pilot-2.0.17
PKGREVISION=		70
CATEGORIES=		comms gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-pilot/2.0/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Handheld synchronisation for GNOME

BUILD_DEPENDS+=		gob2-[0-9]*:../../devel/gob2

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config

CONFIGURE_ARGS+=	--with-pisock=${BUILDLINK_PREFIX.pilot-link-libs}
CONFIGURE_ARGS+=	--with-hal
CONFIGURE_ARGS+=	--with-vfs

.include "../../sysutils/hal/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
