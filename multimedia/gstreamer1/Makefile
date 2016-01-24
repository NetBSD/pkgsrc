# $NetBSD: Makefile,v 1.20 2016/01/24 14:45:21 ryoon Exp $

DISTNAME=	gstreamer-1.6.3
PKGNAME=	${DISTNAME:S/gstreamer/gstreamer1/}
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gstreamer/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gstreamer.freedesktop.org/
COMMENT=	Open source multimedia framework
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex gmake perl pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
FLEX_REQD=		2.5.31

.include "options.mk"

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-controller.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-check.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-net.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-base.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
