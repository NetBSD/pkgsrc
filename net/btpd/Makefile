# $NetBSD: Makefile,v 1.22 2011/12/03 12:44:21 obache Exp $

DISTNAME=	btpd-0.16
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/btpd/btpd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/btpd/btpd/wiki/
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
