# $NetBSD: Makefile,v 1.28 2002/10/26 18:08:54 bouyer Exp $

DISTNAME=		gal-0.19.3
PKGREVISION=		1
CATEGORIES=		gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gal/0.19/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Gnome Application Libraries

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

INCOMPAT_ICONV= SunOS-*-*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libglade/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
