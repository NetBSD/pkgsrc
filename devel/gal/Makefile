# $NetBSD: Makefile,v 1.45 2006/01/24 07:32:02 wiz Exp $

DISTNAME=		gal-0.24
PKGREVISION=		1
CATEGORIES=		gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gal/0.24/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Gnome Application Libraries (gal-1.0 API)

USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	gal.pc.in

INCOMPAT_ICONV= SunOS-*-*

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libunicode/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
