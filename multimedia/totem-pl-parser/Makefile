# $NetBSD: Makefile,v 1.52 2015/01/25 00:07:35 prlw1 Exp $

DISTNAME=	totem-pl-parser-3.4.5
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/totem-pl-parser/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wiki.gnome.org/Apps/Videos
COMMENT=	Totem playlist parser
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

CONFLICTS+=	totem<2.22.0

PKGCONFIG_OVERRIDE+=	totem-plparser-mini.pc.in
PKGCONFIG_OVERRIDE+=	totem-plparser.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
