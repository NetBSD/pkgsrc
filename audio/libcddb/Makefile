# $NetBSD: Makefile,v 1.25 2012/09/12 00:24:41 asau Exp $

DISTNAME=	libcddb-1.3.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcddb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://libcddb.sourceforge.net/
COMMENT=	Library to access data on a CDDB server

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libcddb.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-cdio
GCC_REQD+=		2.95
USE_TOOLS+=		pkg-config

TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
