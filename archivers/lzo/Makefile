# $NetBSD: Makefile,v 1.18 2017/03/05 12:27:32 wiz Exp $

DISTNAME=	lzo-2.10
CATEGORIES=	archivers
MASTER_SITES=	http://www.oberhumer.com/opensource/lzo/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oberhumer.com/opensource/lzo/
COMMENT=	Portable lossless data compression library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		test
PKGCONFIG_OVERRIDE=	lzo2.pc.in

.include "../../mk/bsd.pkg.mk"
