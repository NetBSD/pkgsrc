# $NetBSD: Makefile,v 1.39 2012/09/15 10:05:55 obache Exp $
#

DISTNAME=	totem-pl-parser-2.32.6
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/totem-pl-parser/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	totem playlist parser

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

CONFLICTS+=	totem<2.22.0

PKGCONFIG_OVERRIDE+=	totem-plparser-mini.pc.in
PKGCONFIG_OVERRIDE+=	totem-plparser.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/gmime24/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
