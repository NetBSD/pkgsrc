# $NetBSD: Makefile,v 1.42 2008/03/06 14:53:48 wiz Exp $
#

DISTNAME=		gnome-pilot-2.0.15
PKGREVISION=		5
CATEGORIES=		comms gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-pilot/2.0/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Palm Pilot synchronisation for GNOME

BUILD_DEPENDS+=		gob2-[0-9]*:../../devel/gob2

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config

CONFIGURE_ARGS+=	--with-pisock=${BUILDLINK_PREFIX.pilot-link-libs}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
