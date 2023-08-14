# $NetBSD: Makefile,v 1.6 2023/08/14 05:24:35 wiz Exp $

DISTNAME=	libiptcdata-1.0.4
PKGREVISION=	3
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

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
