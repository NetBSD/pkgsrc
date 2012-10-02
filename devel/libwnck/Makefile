# $NetBSD: Makefile,v 1.86 2012/10/02 17:10:50 tron Exp $
#

DISTNAME=	libwnck-2.30.6
PKGREVISION=	9
CATEGORIES=	devel x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libwnck/2.30/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Library to write pagers and tasklists
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	libwnck-1.0.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXres/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
