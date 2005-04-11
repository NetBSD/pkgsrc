# $NetBSD: Makefile,v 1.19 2005/04/11 21:45:27 tv Exp $
#

DISTNAME=	libgsf-1.11.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgsf/1.11/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 structured file library

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	libgsf-1.pc.in
PKGCONFIG_OVERRIDE+=	libgsf-gnome-1.pc.in

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/libgsf

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
