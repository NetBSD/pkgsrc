# $NetBSD: Makefile,v 1.49 2015/01/17 15:19:04 prlw1 Exp $

DISTNAME=	clutter-1.20.0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/clutter/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Clutter
COMMENT=	Open GL based interactive canvas library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	clutter/cally/cally.pc.in
PKGCONFIG_OVERRIDE+=	clutter/clutter.pc.in

.include "options.mk"

TEST_TARGET=	check

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.atk+=	atk>=2.5.3
.include "../../devel/atk/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.37.3
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.30.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo-gobject+=	cairo-gobject>=1.12.0
.include "../../graphics/cairo-gobject/buildlink3.mk"
BUILDLINK_API_DEPENDS.cogl+=	cogl>=1.17.5
.include "../../graphics/cogl/buildlink3.mk"
BUILDLINK_API_DEPENDS.json-glib+=	json-glib>=0.12.0
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
