# $NetBSD: Makefile,v 1.3 2002/12/01 15:38:34 seb Exp $

DISTNAME=		imapfilter-0.8.4
CATEGORIES=		mail
MASTER_SITES=		http://imapfilter.hellug.gr/source/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://imapfilter.hellug.gr/
COMMENT=		Mail filtering utility for the IMAP

USE_BUILDLINK2=		# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/imapfilter
	${INSTALL_DATA} ${WRKSRC}/sample.imapfilterrc \
		${PREFIX}/share/examples/imapfilter

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
