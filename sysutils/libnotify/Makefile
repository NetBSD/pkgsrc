# $NetBSD: Makefile,v 1.63 2020/03/28 18:16:39 nia Exp $

DISTNAME=	libnotify-0.7.9
PKGREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libnotify/0.7/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/libnotify/
COMMENT=	Desktop notification framework
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

CONFLICTS+=	libnotify07-[0-9]*
SUPERSEDES+=	libnotify07-[0-9]*

USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE=		output/meson-private/libnotify.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install
MAKE_ENV+=			LD_LIBRARY_PATH=${WRKSRC}/output/${PKGBASE}

# Apply removals to post-wrapper transformed arguments.
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,${WRKSRC}/libnotify/libnotify.map

.include "options.mk"

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.26.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gtk3=	build
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
