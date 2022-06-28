# $NetBSD: Makefile,v 1.55 2022/06/28 11:34:21 wiz Exp $

DISTNAME=	isync-1.4.4
PKGREVISION=	1
CATEGORIES=	mail net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=isync/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://isync.sourceforge.net/
COMMENT=	Synchronize a maildir with an imap server
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c99
USE_TOOLS+=		perl
BDB_ACCEPTED=		db4 db5
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
LDFLAGS+=		-lcrypto

post-patch:
	${TOUCH} ${WRKSRC}/configure ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in

BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.include "../../security/openssl/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
