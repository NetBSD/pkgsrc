# $NetBSD: Makefile,v 1.23 2026/01/18 14:28:57 ryoon Exp $

DISTNAME=	opus-1.6.1
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/opus/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://opus-codec.org/
COMMENT=	Totally open, royalty-free, highly versatile audio codec library
LICENSE=	modified-bsd

SUPERSEDES=	opus<=1.0.2

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake perl
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	opus.pc.in

REPLACE_PERL+=	celt/arm/arm2gnu.pl

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
