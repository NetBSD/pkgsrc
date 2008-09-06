# $NetBSD: Makefile,v 1.13 2008/09/06 21:39:52 wiz Exp $

DISTNAME=	btpd-0.12
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.murmeldjur.se/btpd/ \
		http://people.su.se/~rnyberg/btpd/

MAINTAINER=	rnyberg@murmeldjur.se
HOMEPAGE=	http://www.murmeldjur.se/btpd/
COMMENT=	Daemon for file sharing over bittorrent

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.libevent+=	libevent>=0.9

GNU_CONFIGURE=		YES

DOCSDIR=		${PREFIX}/share/doc/btpd
USE_FEATURES.openssl=	threads

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCSDIR}

.include "../../mk/pthread.buildlink3.mk"

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
