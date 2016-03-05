# $NetBSD: Makefile,v 1.38 2016/03/05 11:28:49 jperkin Exp $

DISTNAME=	isync-1.1.1
PKGREVISION=	2
CATEGORIES=	mail net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=isync/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://isync.sourceforge.net/
COMMENT=	Synchronize a maildir with an imap server
LICENSE=	gnu-gpl-v2

BDB_ACCEPTED=		db4 db5
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
LDFLAGS+=		-lcrypto

post-patch:
	${TOUCH} ${WRKSRC}/configure ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in

BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
