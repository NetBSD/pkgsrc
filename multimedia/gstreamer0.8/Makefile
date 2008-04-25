# $NetBSD: Makefile,v 1.17 2008/04/25 20:39:10 joerg Exp $
#

DISTNAME=		gstreamer-0.8.11
PKGNAME=		${DISTNAME:S/gstreamer/gstreamer0.8/}
PKGREVISION=		11
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gstreamer/0.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gstreamer.net/
COMMENT=		Open source multimedia framework

CONFLICTS+=		gstreamer-[0-9]*

USE_TOOLS+=		bison flex

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config flex

CONFIGURE_ARGS+=	--disable-plugin-builddir
CONFIGURE_ARGS+=	--localstatedir=${GST0.8_DBDIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV+=		ac_cv_path_PYTHON=${PYTHONBIN:Q}
CONFIGURE_ARGS+=	HAVE_GTK_DOC=no

PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer-control.pc.in
PKGCONFIG_OVERRIDE+=	pkgconfig/gstreamer.pc.in

REQD_DIRS+=		${GST0.8_DBDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# We must have a glib2 compiled with the RTLD_GLOBAL fix; if not, plugins
# won't work at all.
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.0nb1
.endif
.undef f

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../lang/python/application.mk"
_GSTREAMER0.8_NO_DEPEND=	# defined
.include "../../multimedia/gstreamer0.8/plugins.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
