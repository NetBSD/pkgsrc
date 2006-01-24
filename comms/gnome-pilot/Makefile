# $NetBSD: Makefile,v 1.26 2006/01/24 07:31:58 wiz Exp $
#

DISTNAME=		gnome-pilot-2.0.12
PKGREVISION=		3
CATEGORIES=		comms gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-pilot/2.0/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Palm Pilot synchronisation for GNOME

BUILD_DEPENDS+=		gob2-[0-9]*:../../devel/gob2
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake perl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
