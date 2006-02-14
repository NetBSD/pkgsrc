# $NetBSD: Makefile,v 1.1.1.1 2006/02/14 00:49:23 rillig Exp $

DISTNAME=	btpd-0.8
CATEGORIES=	net
MASTER_SITES=	http://www.murmeldjur.se/btpd/ \
		http://people.su.se/~rnyberg/btpd/
MAINTAINER=	rnyberg@murmeldjur.se
HOMEPAGE=	http://www.murmeldjur.se/btpd/
COMMENT=	Daemon for file sharing over bittorrent

GNU_CONFIGURE=	YES

DOCSDIR=${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
