# $NetBSD: Makefile,v 1.29 2023/10/24 22:10:12 wiz Exp $

DISTNAME=	btpd-0.16
PKGREVISION=	5
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
