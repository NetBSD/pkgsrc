# $NetBSD: Makefile,v 1.11 2004/10/03 00:18:15 tv Exp $

DISTNAME=	acme-2.4.2
PKGNAME=	gnome-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/acme/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Small GNOME tool to make use of the multimedia buttons

DEPENDS=	gnome2-control-center>=2.0:../../x11/gnome2-control-center

BUILDLINK_DEPENDS.libwnck+=	libwnck>=2.6.2.1

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_X11=		yes
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		acme.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
