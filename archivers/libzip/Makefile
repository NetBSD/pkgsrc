# $NetBSD: Makefile,v 1.2 2005/07/14 16:56:24 wiz Exp $
#

DISTNAME=		libzip-0.6.1
CATEGORIES=		archivers devel
MASTER_SITES=		http://www.nih.at/libzip/

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.nih.at/libzip/
COMMENT=		C library to manipulate zip archives

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libzip.pc.in
GNU_CONFIGURE=		yes

TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
