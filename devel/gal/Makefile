# $NetBSD: Makefile,v 1.26 2002/09/21 10:49:26 jlam Exp $

DISTNAME=		gal-0.19.3
PKGREVISION=		1
CATEGORIES=		gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gal/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Gnome Application Libraries

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
