# $NetBSD: Makefile,v 1.3 2020/03/08 16:50:03 wiz Exp $

DISTNAME=	libiptcdata-1.0.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libiptcdata/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libiptcdata.sourceforge.net/
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
