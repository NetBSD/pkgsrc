# $NetBSD: Makefile,v 1.14 2004/10/03 00:17:49 tv Exp $
#

DISTNAME=		dante-1.1.14
PKGREVISION=		1
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.inet.no/pub/socks/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.inet.no/dante/
COMMENT=		BSD-licensed socks 4/5 proxy suite

CONFLICTS=		socks4-[0-9]*

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--with-socks-conf=${PKG_SYSCONFDIR}/socks.conf
CONFIGURE_ARGS+=	--with-sockd-conf=${PKG_SYSCONFDIR}/sockd.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dante
.for cfg in sockd.conf socks-simple.conf socks.conf
	${INSTALL_DATA} ${WRKSRC}/example/${cfg} ${PREFIX}/share/examples/dante
.endfor

.include "../../mk/bsd.pkg.mk"
