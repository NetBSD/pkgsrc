# $NetBSD: Makefile,v 1.1.1.1 2000/10/15 17:29:14 rh Exp $
#

DISTNAME=		dante-1.1.4
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.inet.no/pub/socks/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.inet.no/dante/

CONFLICTS=		socks4-*

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-socks-conf=${PREFIX}/etc/socks.conf
CONFIGURE_ARGS+=	--with-sockd-conf=${PREFIX}/etc/sockd.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dante
.for cfg in sockd.conf socks-simple.conf socks.conf
	${INSTALL_DATA} ${WRKSRC}/example/${cfg} ${PREFIX}/share/examples/dante
.endfor

.include "../../mk/bsd.pkg.mk"
