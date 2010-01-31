# $NetBSD: Makefile,v 1.10 2010/01/31 23:34:34 wiz Exp $
#

DISTNAME=		libzip-0.9.2
CATEGORIES=		archivers devel
MASTER_SITES=		http://www.nih.at/libzip/

OWNER=			dillo@NetBSD.org
HOMEPAGE=		http://www.nih.at/libzip/
COMMENT=		C library to manipulate zip archives
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libzip.pc.in
GNU_CONFIGURE=		yes

TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
