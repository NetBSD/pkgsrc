# $NetBSD: Makefile,v 1.27 2003/04/17 23:23:14 salo Exp $

DISTNAME=		gnome-vfs-1.0.5
PKGREVISION=		1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-vfs/1.0/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Virtual File System

BUILD_USES_MSGFMT=	YES
BUILDLINK_DEPENDS.gnome-mime-data=	gnome-mime-data>=2.0.1

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../databases/gnome-mime-data/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
