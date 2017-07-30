# $NetBSD: Makefile,v 1.83 2017/07/30 22:47:51 wiz Exp $
#

DISTNAME=		gturing-0.1.1
PKGREVISION=		60
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gturing/0.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		GNOME2 turing machine emulator

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGDK_PIXBUF_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGNOME_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DBONOBO_DISABLE_DEPRECATED

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/bsd.pkg.mk"
