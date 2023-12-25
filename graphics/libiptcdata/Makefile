# $NetBSD: Makefile,v 1.7 2023/12/25 16:02:47 nros Exp $

DISTNAME=	libiptcdata-1.0.4
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libiptcdata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libiptcdata.sourceforge.net/
COMMENT=	Library to parse IPTC metadata
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config intltool gettext
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES+=		c c++

PKGCONFIG_OVERRIDE+=	libiptcdata/libiptcdata.pc.in

CONFIGURE_ARGS+=	--disable-python

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
