# $NetBSD: Makefile,v 1.27 2017/01/07 15:43:32 zafer Exp $

DISTNAME=		libzip-1.1.3
PKGREVISION=		1
CATEGORIES=		archivers devel
MASTER_SITES=		https://www.nih.at/libzip/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.nih.at/libzip/
COMMENT=		C library to manipulate zip archives
LICENSE=		modified-bsd

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libzip.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:build

TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
