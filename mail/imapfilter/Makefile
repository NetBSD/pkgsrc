# $NetBSD: Makefile,v 1.13 2004/04/18 05:01:43 snj Exp $

DISTNAME=		imapfilter-0.9.5
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://imapfilter.hellug.gr/source/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://imapfilter.hellug.gr/
COMMENT=		Mail filtering utility for the IMAP

USE_BUILDLINK3=		yes

CFLAGS+=		-I${BUILDLINK_PREFIX.openssl}/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.openssl}/lib -Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
LDFLAGS.SunOS+=		-lsocket -lnsl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/imapfilter
	${INSTALL_DATA} ${WRKSRC}/sample.imapfilterrc \
		${PREFIX}/share/examples/imapfilter

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
