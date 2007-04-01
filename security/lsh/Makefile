# $NetBSD: Makefile,v 1.16 2007/04/01 21:26:48 wiz Exp $
#

DISTNAME=		lsh-2.0.2
CATEGORIES=		security
MASTER_SITES=		http://www.lysator.liu.se/~nisse/archive/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~nisse/lsh/
COMMENT=		SSH2 client/server

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gm4
CONFIGURE_ARGS+=	--disable-openssl --disable-pam
INFO_FILES=		yes

# lcp test depends on /bin/bash and thus fails, others work
TEST_TARGET=		check

# man/man8/sftp-server.8
CONFLICTS+=		openssh-[0-9]* openssh+gssapi-[0-9]*

# src/nettle/examples/nettle-openssl.c needs des_key*
USE_OLD_DES_API=	yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/liboop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
