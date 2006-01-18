# $NetBSD: Makefile,v 1.1.1.1 2006/01/18 15:35:48 jmmv Exp $
#

DISTNAME=		gstreamer-0.10.1
PKGNAME=		${DISTNAME:S/gstreamer/gstreamer0.10/}
CATEGORIES=		multimedia gnome
MASTER_SITES=		http://gstreamer.freedesktop.org/src/gstreamer/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		Open source multimedia framework

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config

CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ENV+=		ac_cv_path_PYTHON=${TRUE:Q}
CONFIGURE_ENV+=		ac_cv_path_XSLTPROC=${TRUE:Q}

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-base-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-base.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-check-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-check.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-controller-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-controller.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-dataprotocol-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-dataprotocol.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-net-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-net.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-uninstalled.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# We must have a glib2 compiled with the RTLD_GLOBAL fix; if not, plugins
# won't work at all.
BUILDLINK_DEPENDS.glib2+=	glib2>=2.4.0nb1
.endif
.undef f

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
