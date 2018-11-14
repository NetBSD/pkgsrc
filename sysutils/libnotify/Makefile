# $NetBSD: Makefile,v 1.49 2018/11/14 22:22:26 kleink Exp $

DISTNAME=	libnotify-0.7.7
PKGREVISION=	5
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libnotify/0.7/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/libnotify/
COMMENT=	Desktop notification framework
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	libnotify07-[0-9]*
SUPERSEDES+=	libnotify07-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	libnotify.pc.in

.include "options.mk"

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.26.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gtk3=	build
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
