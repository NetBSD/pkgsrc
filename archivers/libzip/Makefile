# $NetBSD: Makefile,v 1.13 2012/09/11 19:46:56 asau Exp $
#

DISTNAME=		libzip-0.10.1
CATEGORIES=		archivers devel
MASTER_SITES=		http://www.nih.at/libzip/
EXTRACT_SUFX=		.tar.bz2

OWNER=			dillo@NetBSD.org
HOMEPAGE=		http://www.nih.at/libzip/
COMMENT=		C library to manipulate zip archives
LICENSE=		modified-bsd

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libzip.pc.in
GNU_CONFIGURE=		yes

TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
