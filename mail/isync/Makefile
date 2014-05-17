# $NetBSD: Makefile,v 1.34 2014/05/17 04:06:56 schmonz Exp $

DISTNAME=	isync-1.1.0
CATEGORIES=	mail net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=isync/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://isync.sourceforge.net/
COMMENT=	Synchronize a maildir with an imap server
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
