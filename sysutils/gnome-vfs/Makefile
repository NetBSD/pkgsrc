# $NetBSD: Makefile,v 1.35 2004/01/03 18:49:52 reed Exp $

DISTNAME=		gnome-vfs-1.0.5
PKGREVISION=		5
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-vfs/1.0/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Virtual File System

BUILD_USES_MSGFMT=	YES
BUILDLINK_DEPENDS.gnome-mime-data=	gnome-mime-data>=2.0.1

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../converters/libiconv/buildlink2.mk"

.if defined(ICONV_IS_GNU)
CONFIGURE_ARGS+=	--with-libiconv=yes
.endif

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../databases/gnome-mime-data/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
