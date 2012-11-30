# $NetBSD: Makefile,v 1.1 2012/11/30 15:49:47 ryoon Exp $
#

DISTNAME=	libsecret-0.12
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsecret/0.12/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://live.gnome.org/Libsecret
COMMENT=	GObject based library for accessing the Secret Service API
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config

PKGCONFIG_OVERRIDE+=	libsecret/libsecret-unstable.pc.in
PKGCONFIG_OVERRIDE+=	libsecret/libsecret.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
