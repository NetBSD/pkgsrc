# $NetBSD: Makefile,v 1.8 2003/08/23 20:52:57 seb Exp $

DISTNAME=		imapfilter-0.9.2
CATEGORIES=		mail
MASTER_SITES=		http://imapfilter.hellug.gr/source/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://imapfilter.hellug.gr/
COMMENT=		Mail filtering utility for the IMAP

USE_BUILDLINK2=		# defined

CFLAGS+=		-I${BUILDLINK_PREFIX.openssl}/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.openssl}/lib -Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/imapfilter
	${INSTALL_DATA} ${WRKSRC}/sample.imapfilterrc \
		${PREFIX}/share/examples/imapfilter

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
