# $NetBSD: Makefile,v 1.47 2013/05/24 18:23:32 wiz Exp $
#

DISTNAME=	totem-pl-parser-3.4.3
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/totem-pl-parser/3.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Totem playlist parser

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

CONFLICTS+=	totem<2.22.0

PKGCONFIG_OVERRIDE+=	totem-plparser-mini.pc.in
PKGCONFIG_OVERRIDE+=	totem-plparser.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/gmime24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
