# $NetBSD: Makefile,v 1.7 2003/12/14 19:53:11 jmmv Exp $
#

DISTNAME=	libgsf-1.8.2
PKGREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgsf/1.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME2 structured file library

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libgsf-1.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libgsf-gnome-1.pc.in

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html/libgsf

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
