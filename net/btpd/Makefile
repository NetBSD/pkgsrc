# $NetBSD: Makefile,v 1.7 2007/04/25 16:39:40 tnn Exp $

DISTNAME=	btpd-0.11
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.murmeldjur.se/btpd/ \
		http://people.su.se/~rnyberg/btpd/

MAINTAINER=	rnyberg@murmeldjur.se
HOMEPAGE=	http://www.murmeldjur.se/btpd/
COMMENT=	Daemon for file sharing over bittorrent

BUILDLINK_API_DEPENDS.libevent+=	libevent>=0.9

GNU_CONFIGURE=	YES

DOCSDIR=	${PREFIX}/share/doc/btpd

post-install:
	${INSTALL_DATA_DIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
