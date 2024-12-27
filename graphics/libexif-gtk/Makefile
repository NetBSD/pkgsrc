# $NetBSD: Makefile,v 1.72 2024/12/27 08:19:59 wiz Exp $

DISTNAME=	libexif-gtk-0.5.0
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=libexif/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libexif.sourceforge.net/
COMMENT=	EXIF file library (GTK2 interface)
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libexif-gtk/libexif-gtk.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
