# $NetBSD: Makefile,v 1.38 2004/02/14 17:21:37 jlam Exp $

DISTNAME=		gal-0.22
PKGREVISION=		4
CATEGORIES=		gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gal/0.22/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Gnome Application Libraries

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

INCOMPAT_ICONV= SunOS-*-*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
