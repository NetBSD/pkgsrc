# $NetBSD: Makefile,v 1.20 2004/11/30 18:26:39 wiz Exp $
#

DISTNAME=		gnome-pilot-0.1.71
PKGREVISION=		11
CATEGORIES=		comms gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-pilot/0.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Palm Pilot synchronisation for GNOME

DEPENDS+=		gob-[0-9]*:../../devel/gob
BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.gnome-panel=	gnome-panel<2.0

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
USE_LIBINTL=		YES
USE_LIBTOOL=		YES
USE_PERL5=		build

CONFIGURE_ARGS+=	--with-pisock=${LOCALBASE}

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
