# $NetBSD: Makefile,v 1.26 2018/11/14 22:21:18 kleink Exp $

DISTNAME=	libwnck-3.24.1
PKGNAME=	${DISTNAME:S/libwnck/libwnck3/}
PKGREVISION=	5
CATEGORIES=	devel x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libwnck/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Library to write pagers and tasklists
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	libwnck-3.0.pc.in

# wnckutils conflict with devel/libwnck, but also probably aren't used
CONFIGURE_ARGS+=	--disable-tools

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.22.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
