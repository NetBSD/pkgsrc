# $NetBSD: Makefile,v 1.18 2001/10/05 06:58:46 rh Exp $

DISTNAME=		gal-0.13
CATEGORIES=		gnome devel
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gal/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Gnome Application Libraries

DEPENDS+=		libunicode>=0.4:../../textproc/libunicode

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../converters/libiconv/buildlink.mk"
.include "../../sysutils/gnome-vfs/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
