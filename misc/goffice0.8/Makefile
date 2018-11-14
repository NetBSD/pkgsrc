# $NetBSD: Makefile,v 1.46 2018/11/14 22:22:02 kleink Exp $
#

DISTNAME=		goffice-0.8.17
PKGNAME=		${DISTNAME:S/goffice/goffice0.8/}
PKGREVISION=		25
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/goffice/0.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Library of document-centric objects and utilities
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgoffice.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
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
