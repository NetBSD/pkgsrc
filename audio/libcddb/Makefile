# $NetBSD: Makefile,v 1.12 2004/11/10 15:16:47 adam Exp $

DISTNAME=	libcddb-0.9.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcddb/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://libcddb.sourceforge.net/
COMMENT=	Library to access data on a CDDB server

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libcddb.pc.in
GNU_CONFIGURE=		yes
GCC_REQD+=		2.95

TEST_TARGET=		check

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
