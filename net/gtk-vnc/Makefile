# $NetBSD: Makefile,v 1.1.1.1 2009/04/06 10:17:32 wiz Exp $
#

DISTNAME=	gtk-vnc-0.3.8
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk-vnc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtk-vnc.sourceforge.net/
COMMENT=	VNC viewer widget for GTK

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gtk-vnc-1.0.pc.in
PY_PATCHPLIST=	yes

CONFIGURE_ARGS+=	--with-coroutine=gthread

.include "options.mk"

#VIEW_REQUIRED=0.6.0
#libview

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=1.4.0
.include "../../security/gnutls/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
