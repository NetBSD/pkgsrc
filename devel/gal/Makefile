# $NetBSD: Makefile,v 1.36 2003/11/12 01:31:48 salo Exp $

DISTNAME=		gal-0.22
PKGREVISION=		3
CATEGORIES=		gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gal/0.22/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Gnome Application Libraries

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

INCOMPAT_ICONV= SunOS-*-*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
