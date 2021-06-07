# $NetBSD: Makefile,v 1.28 2021/06/07 09:12:32 adam Exp $

DISTNAME=	libogg-1.3.5
CATEGORIES=	multimedia devel
MASTER_SITES=	http://downloads.xiph.org/releases/ogg/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	ogg.pc.in
TEST_TARGET=		check

GCC_REQD+=	2.95.3

.include "../../mk/bsd.pkg.mk"
