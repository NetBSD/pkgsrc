# $NetBSD: Makefile,v 1.44 2004/10/03 00:18:15 tv Exp $

DISTNAME=		gnome-vfs-1.0.5
PKGREVISION=		6
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-vfs/1.0/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Virtual File System

BUILD_USES_MSGFMT=	YES
BUILDLINK_DEPENDS.gnome-mime-data=	gnome-mime-data>=2.0.1

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}

CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
