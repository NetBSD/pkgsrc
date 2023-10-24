# $NetBSD: Makefile,v 1.34 2023/10/24 22:10:52 wiz Exp $

DISTNAME=		netpgp-20140220
PKGREVISION=		10
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		PGP signing, verification, encryption and decryption program
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
