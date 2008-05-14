# $NetBSD: Makefile,v 1.2 2008/05/14 18:34:23 drochner Exp $
#

DISTNAME=	totem-pl-parser-2.22.3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/totem-pl-parser/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	totem playlist parser

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake

CONFLICTS+=	totem<2.22.0

PKGCONFIG_OVERRIDE+=	totem-plparser-mini.pc.in
PKGCONFIG_OVERRIDE+=	totem-plparser.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
