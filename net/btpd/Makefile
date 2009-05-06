# $NetBSD: Makefile,v 1.17 2009/05/06 15:54:50 snj Exp $

DISTNAME=	btpd-0.15
CATEGORIES=	net
MASTER_SITES=	http://www.murmeldjur.se/btpd/ \
		http://people.su.se/~rnyberg/btpd/

MAINTAINER=	rnyberg@murmeldjur.se
HOMEPAGE=	http://www.murmeldjur.se/btpd/
COMMENT=	Daemon for file sharing over bittorrent

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

DOCSDIR=		${PREFIX}/share/doc/btpd
USE_FEATURES.openssl=	threads

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCSDIR}

.include "../../mk/pthread.buildlink3.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
