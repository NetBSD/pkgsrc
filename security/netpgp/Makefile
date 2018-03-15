# $NetBSD: Makefile,v 1.29 2018/03/15 20:21:52 khorben Exp $

DISTNAME=		netpgp-20140220
PKGREVISION=		7
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		PGP signing, verification, encryption and decryption program
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
