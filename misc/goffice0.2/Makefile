# $NetBSD: Makefile,v 1.5 2008/01/18 05:08:34 tnn Exp $
#

DISTNAME=		goffice-0.2.2
PKGNAME=		goffice0.2-0.2.2
PKGREVISION=		5
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/goffice/0.2/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ftp.gnome.org/pub/GNOME/sources/goffice/0.2/
COMMENT=		Library of document-centric objects and utilities (0.2 branch)

CONFLICTS+=		goffice<0.3

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgoffice-1.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.3
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgnomeprint+=	libgnomeprint>=2.8.2
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
