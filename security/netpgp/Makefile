# $NetBSD: Makefile,v 1.2 2009/05/25 06:50:53 agc Exp $

DISTNAME=		netpgp-20090525
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		PGP signing, verification, encryption and decryption program
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
