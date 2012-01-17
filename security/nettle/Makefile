# $NetBSD: Makefile,v 1.6 2012/01/17 21:43:21 sbd Exp $

DISTNAME=	nettle-2.4
CATEGORIES=	devel security
MASTER_SITES=	http://www.lysator.liu.se/~nisse/archive/ \
		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/~nisse/nettle/
COMMENT=	Cryptographic library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-openssl

INFO_FILES=		yes
TEST_TARGET=		check
PKGCONFIG_OVERRIDE=	hogweed.pc.in
PKGCONFIG_OVERRIDE+=	nettle.pc.in

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
