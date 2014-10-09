# $NetBSD: Makefile,v 1.22 2014/10/09 14:06:43 wiz Exp $

DISTNAME=	libogg-1.3.2
CATEGORIES=	multimedia devel
MASTER_SITES=	http://downloads.xiph.org/releases/ogg/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xiph.org/ogg/
COMMENT=	Ogg project codecs library
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

GCC_REQD+=	2.95.3

PKGCONFIG_OVERRIDE+=	ogg.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
