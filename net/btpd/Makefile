# $NetBSD: Makefile,v 1.28 2020/01/18 21:50:10 jperkin Exp $

DISTNAME=	btpd-0.16
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	https://cloud.github.com/downloads/btpd/btpd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/btpd/btpd/wiki/
COMMENT=	Daemon for file sharing over bittorrent
LICENSE=	2-clause-bsd

GNU_CONFIGURE=		YES

DOCSDIR=		${PREFIX}/share/doc/btpd
USE_FEATURES.openssl=	threads

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCSDIR}

.include "../../mk/pthread.buildlink3.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
