# $NetBSD: Makefile,v 1.1.1.1 2002/05/04 00:03:29 jtb Exp $

DISTNAME=		imapfilter-0.7.2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=imapfilter/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://imapfilter.sourceforge.net
COMMENT=		Mail filtering utility for the IMAP

USE_BUILDLINK_ONLY=	# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/imapfilter
	${INSTALL_DATA} ${WRKSRC}/sample.imapfilterrc \
		${PREFIX}/share/examples/imapfilter

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
