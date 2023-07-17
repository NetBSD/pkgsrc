# $NetBSD: Makefile,v 1.31 2023/07/17 22:00:24 nia Exp $

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

.include "../../mk/bsd.pkg.mk"
