# $NetBSD: Makefile,v 1.6 2003/06/02 01:18:45 jschauma Exp $

DISTNAME=		imapfilter-0.8.7
CATEGORIES=		mail
MASTER_SITES=		http://imapfilter.hellug.gr/source/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://imapfilter.hellug.gr/
COMMENT=		Mail filtering utility for the IMAP

USE_BUILDLINK2=		# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/imapfilter
	${INSTALL_DATA} ${WRKSRC}/sample.imapfilterrc \
		${PREFIX}/share/examples/imapfilter

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
