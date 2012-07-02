# $NetBSD: Makefile,v 1.21 2012/07/02 19:23:29 drochner Exp $
#

DISTNAME=	gtk-vnc-0.3.10
PKGREVISION=	15
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-vnc/0.3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/gtk-vnc
COMMENT=	VNC viewer widget for GTK

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config msgfmt intltool

PKGCONFIG_OVERRIDE+=	gtk-vnc-1.0.pc.in
PY_PATCHPLIST=	yes

CONFIGURE_ARGS+=	--with-coroutine=gthread

.include "options.mk"

#VIEW_REQUIRED=0.6.0
#libview

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
# libview is only used for an example which is not installed
#.include "../../devel/libview/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=1.4.0
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
