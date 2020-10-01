# $NetBSD: Makefile,v 1.31 2020/10/01 11:58:16 prlw1 Exp $

DISTNAME=	libwnck-3.36.0
PKGNAME=	${DISTNAME:S/libwnck/libwnck3/}
CATEGORIES=	devel x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libwnck/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Library to write pagers and tasklists
LICENSE=	gnu-lgpl-v2

#GNU_CONFIGURE=		yes
#USE_PKGLOCALEDIR=	yes
#USE_TOOLS+=		gmake msgfmt pkg-config
USE_TOOLS+=		pkg-config
#USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	libwnck-3.0.pc.in

# wnckutils conflict with devel/libwnck, but also probably aren't used
MESON_ARGS+=	-Dinstall_tools=false

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../x11/startup-notification/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.22.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
