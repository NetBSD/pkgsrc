# $NetBSD: Makefile,v 1.23 2017/05/10 10:45:26 jperkin Exp $
#

DISTNAME=		lsh-2.0.4
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://www.lysator.liu.se/~nisse/archive/
MASTER_SITES+=		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lysator.liu.se/~nisse/lsh/
COMMENT=		SSH2 client/server
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake gm4 bash:run
REPLACE_BASH+=		src/lcp
CONFIGURE_ARGS+=	--disable-openssl --disable-pam --disable-kerberos
INFO_FILES=		yes

# lcp test depends on /bin/bash and thus fails, others work
TEST_TARGET=		check

# man/man8/sftp-server.8
CONFLICTS+=		openssh-[0-9]* openssh+gssapi-[0-9]*

# src/nettle/examples/nettle-openssl.c needs des_key*
USE_OLD_DES_API=	yes

.include "../../devel/argp/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/liboop/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
