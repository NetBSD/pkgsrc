# $NetBSD: Makefile,v 1.41 2018/08/22 09:45:49 wiz Exp $

DISTNAME=	gstreamer-1.14.2
PKGNAME=	${DISTNAME:S/gstreamer/gstreamer1/}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gstreamer/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/
COMMENT=	Open source multimedia framework
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bison flex gmake perl pkg-config
GNU_CONFIGURE=		yes
FLEX_REQD=		2.5.31

.include "options.mk"

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-controller.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-check.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-net.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-base.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
