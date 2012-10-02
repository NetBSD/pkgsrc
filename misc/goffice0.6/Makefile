# $NetBSD: Makefile,v 1.30 2012/10/02 17:11:34 tron Exp $
#

DISTNAME=		goffice-0.6.6
PKGNAME=		goffice0.6-0.6.6
PKGREVISION=		21
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/goffice/0.6/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Library of document-centric objects and utilities

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		goffice<0.4.2nb1 goffice0.5<0.5.4

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgoffice.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gnome
USE_TOOLS+=		gmake intltool msgfmt pkg-config

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.8.1
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.libart+=	libart>=2.3.11
.include "../../graphics/libart/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
