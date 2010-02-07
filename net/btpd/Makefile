# $NetBSD: Makefile,v 1.19 2010/02/07 19:15:43 zafer Exp $

DISTNAME=	btpd-0.15
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.murmeldjur.se/btpd/

MAINTAINER=	rnyberg@murmeldjur.se
HOMEPAGE=	http://www.murmeldjur.se/btpd/
COMMENT=	Daemon for file sharing over bittorrent
LICENSE=	2-clause-bsd

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
