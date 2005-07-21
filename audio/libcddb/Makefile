# $NetBSD: Makefile,v 1.19 2005/07/21 16:29:43 wiz Exp $

DISTNAME=	libcddb-1.0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcddb/}

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

TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
