# $NetBSD: Makefile,v 1.21 2011/07/22 11:58:13 hauke Exp $

DISTNAME=	btpd-0.16
CATEGORIES=	net
MASTER_SITES=	https://cloud.github.com/downloads/btpd/btpd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/btpd/btpd/wiki/
COMMENT=	Daemon for file sharing over bittorrent
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=		curl

GNU_CONFIGURE=		YES

DOCSDIR=		${PREFIX}/share/doc/btpd
USE_FEATURES.openssl=	threads

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCSDIR}

.include "../../mk/pthread.buildlink3.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
