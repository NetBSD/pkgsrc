# $NetBSD: Makefile,v 1.15 2013/04/01 16:03:31 wiz Exp $

DISTNAME=		libzip-0.11
CATEGORIES=		archivers devel
MASTER_SITES=		http://www.nih.at/libzip/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		wiz@NetBSD.org
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
