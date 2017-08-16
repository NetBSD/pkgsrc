# $NetBSD: Makefile,v 1.24 2017/08/16 20:21:12 wiz Exp $

DISTNAME=	libogg-1.3.2
CATEGORIES=	multimedia devel
MASTER_SITES=	http://downloads.xiph.org/releases/ogg/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

GCC_REQD+=	2.95.3

PKGCONFIG_OVERRIDE+=	ogg.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

# Aggressive optimisation causes configure tests to fail.
.if ${OPSYS} == "Darwin" && ${PKGSRC_COMPILER} == "gcc"
BUILDLINK_TRANSFORM+=	opt:-O4:-O2
.endif

.include "../../mk/bsd.pkg.mk"
