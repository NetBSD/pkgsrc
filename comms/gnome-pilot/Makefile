# $NetBSD: Makefile,v 1.11 2003/11/12 01:31:47 salo Exp $
#

DISTNAME=		gnome-pilot-0.1.71
PKGREVISION=		5
CATEGORIES=		comms gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-pilot/0.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Palm Pilot synchronisation for GNOME

DEPENDS+=		gnome1-dirs>=1.2:../../misc/gnome1-dirs
DEPENDS+=		gob-[0-9]*:../../devel/gob
BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.gnome-panel=	gnome-panel<2.0

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBINTL=		YES
USE_LIBTOOL=		YES
USE_PERL5=		build
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-pisock=${LOCALBASE}

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
