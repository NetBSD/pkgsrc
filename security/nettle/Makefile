# $NetBSD: Makefile,v 1.3 2011/05/06 19:30:13 alnsn Exp $

DISTNAME=	nettle-2.1
CATEGORIES=	devel security
MASTER_SITES=	http://www.lysator.liu.se/~nisse/archive/ \
		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/~nisse/nettle/
COMMENT=	Cryptographic library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-openssl
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib

INFO_FILES=		yes
TEST_TARGET=		check

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
