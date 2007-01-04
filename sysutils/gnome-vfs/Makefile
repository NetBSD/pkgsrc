# $NetBSD: Makefile,v 1.59 2007/01/04 01:19:09 rillig Exp $

DISTNAME=		gnome-vfs-1.0.5
PKGREVISION=		12
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-vfs/1.0/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Virtual File System

BROKEN_GETTEXT_DETECTION=	yes
BUILDLINK_API_DEPENDS.gnome-mime-data+=	gnome-mime-data>=2.0.1

USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_TOOLS+=		gmake msgfmt pkg-config perl:run
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}

CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=yes

REPLACE_PERL.extfs=	a deb.in mailfs rpms tar
REPLACE_PERL+=		${REPLACE_PERL.extfs:S,^,modules/extfs/,}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/gnome-mime-data/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
