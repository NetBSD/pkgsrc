# $NetBSD: Makefile,v 1.8 2007/08/16 09:27:04 tnn Exp $

DISTNAME=	btpd-0.11
PKGREVISION=	4
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
