# $NetBSD: Makefile,v 1.9 2002/09/10 06:10:04 jlam Exp $
#

DISTNAME=		dante-1.1.13
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.inet.no/pub/socks/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.inet.no/dante/
COMMENT=		BSD-licensed socks 4/5 proxy suite

CONFLICTS=		socks4-[0-9]*

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--with-socks-conf=${PKG_SYSCONFDIR}/socks.conf
CONFIGURE_ARGS+=	--with-sockd-conf=${PKG_SYSCONFDIR}/sockd.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dante
.for cfg in sockd.conf socks-simple.conf socks.conf
	${INSTALL_DATA} ${WRKSRC}/example/${cfg} ${PREFIX}/share/examples/dante
.endfor

.include "../../mk/bsd.pkg.mk"
