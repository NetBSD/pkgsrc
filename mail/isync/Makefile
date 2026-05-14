# $NetBSD: Makefile,v 1.61 2026/05/14 13:15:13 ktnb Exp $

DISTNAME=	isync-1.5.1
CATEGORIES=	mail net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=isync/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	https://isync.sourceforge.net/
COMMENT=	Synchronize a maildir with an imap server
LICENSE=	gnu-gpl-v2

USE_CC_FEATURES=	c11
USE_TOOLS+=		perl
BDB_ACCEPTED=		db4 db5
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
LDFLAGS+=		-lcrypto

CFLAGS.SunOS+=	-D__EXTENSIONS__

post-patch:
	${TOUCH} ${WRKSRC}/configure ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in

BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.include "../../security/openssl/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
