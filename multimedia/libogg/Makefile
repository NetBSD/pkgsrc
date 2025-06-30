# $NetBSD: Makefile,v 1.32 2025/06/30 19:18:38 adam Exp $

DISTNAME=	libogg-1.3.6
CATEGORIES=	multimedia devel
MASTER_SITES=	http://downloads.xiph.org/releases/ogg/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	ogg.pc.in
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
