# $NetBSD: Makefile,v 1.30 2022/07/25 11:12:26 wiz Exp $

DISTNAME=	libogg-1.3.5
PKGREVISION=	1
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

GCC_REQD+=	2.95.3

.include "../../mk/bsd.pkg.mk"
