# $NetBSD: Makefile,v 1.2 2002/10/25 11:58:54 wiz Exp $

DISTNAME=		imapfilter-0.7.2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=imapfilter/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://imapfilter.sourceforge.net
COMMENT=		Mail filtering utility for the IMAP

USE_BUILDLINK2=		# defined

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/imapfilter
	${INSTALL_DATA} ${WRKSRC}/sample.imapfilterrc \
		${PREFIX}/share/examples/imapfilter

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
