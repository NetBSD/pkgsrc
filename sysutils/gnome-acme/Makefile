# $NetBSD: Makefile,v 1.2 2003/12/28 23:37:07 jmmv Exp $

DISTNAME=	acme-2.4.2
PKGNAME=	gnome-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/acme/2.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Small GNOME tool to make use of the multimedia buttons

DEPENDS=	gnome2-control-center>=2.0:../../x11/gnome2-control-center

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_X11=		yes
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		acme.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libwnck/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
