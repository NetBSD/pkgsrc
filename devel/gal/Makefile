# $NetBSD: Makefile,v 1.42 2004/11/30 18:26:39 wiz Exp $

DISTNAME=		gal-0.22
PKGREVISION=		6
CATEGORIES=		gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gal/0.22/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Gnome Application Libraries (gal-1.0 API)

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

INCOMPAT_ICONV= SunOS-*-*

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/libunicode/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
