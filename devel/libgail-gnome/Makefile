# $NetBSD: Makefile,v 1.46 2012/07/15 08:22:48 wiz Exp $
#

DISTNAME=	libgail-gnome-1.20.1
PKGREVISION=	18
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgail-gnome/1.20/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.gnome.org/projects/gap/
COMMENT=	GNOME Accessibility Implementation Library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config gmake

PKGCONFIG_OVERRIDE=	libgail-gnome.pc.in

.include "../../devel/at-spi/buildlink3.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
