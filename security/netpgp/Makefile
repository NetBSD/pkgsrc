# $NetBSD: Makefile,v 1.31 2020/01/18 23:35:10 rillig Exp $

DISTNAME=		netpgp-20140220
PKGREVISION=		8
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		PGP signing, verification, encryption and decryption program
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
