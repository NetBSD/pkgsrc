# $NetBSD: Makefile,v 1.25 2002/09/10 16:06:38 wiz Exp $

DISTNAME=		gal-0.19.3
PKGREVISION=		1
CATEGORIES=		gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gal/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Gnome Application Libraries

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../sysutils/gnome-vfs/buildlink.mk"
.include "../../textproc/libunicode/buildlink.mk"

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
