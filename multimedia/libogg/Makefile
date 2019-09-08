# $NetBSD: Makefile,v 1.27 2019/09/08 19:11:30 dbj Exp $

DISTNAME=	libogg-1.3.4
PKGREVISION=	1
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
