# $NetBSD: Makefile,v 1.19 2020/01/26 17:30:40 rillig Exp $

DISTNAME=	lzo-2.10
CATEGORIES=	archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/lzo/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.oberhumer.com/opensource/lzo/
COMMENT=	Portable lossless data compression library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		test
PKGCONFIG_OVERRIDE=	lzo2.pc.in

.include "../../mk/bsd.pkg.mk"
