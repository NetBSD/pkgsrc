# $NetBSD: Makefile,v 1.21 2002/03/13 17:36:48 fredb Exp $

DISTNAME=		gal-0.19
PKGREVISION=		1
CATEGORIES=		gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gal/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Gnome Application Libraries

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../converters/libiconv/buildlink.mk"
.include "../../textproc/libunicode/buildlink.mk"
.include "../../sysutils/gnome-vfs/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
