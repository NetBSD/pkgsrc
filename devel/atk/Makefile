# $NetBSD: Makefile,v 1.98 2017/10/15 23:19:11 prlw1 Exp $

DISTNAME=		atk-2.24.0
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/atk/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://developer.gnome.org/atk/
COMMENT=		Set of interfaces for accessibility
LICENSE=		gnu-lgpl-v2

USE_TOOLS+=		gmake pkg-config msgfmt
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	atk.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.31.2
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
