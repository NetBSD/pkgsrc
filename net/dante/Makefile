# $NetBSD: Makefile,v 1.5 2001/12/19 22:25:30 agc Exp $
#

DISTNAME=		dante-1.1.9
CATEGORIES=		net security
MASTER_SITES=		ftp://ftp.inet.no/pub/socks/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.inet.no/dante/
COMMENT=		BSD-licensed socks 4/5 proxy suite

CONFLICTS=		socks4-[0-9]*

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ARGS+=	--with-socks-conf=${PREFIX}/etc/socks.conf
CONFIGURE_ARGS+=	--with-sockd-conf=${PREFIX}/etc/sockd.conf

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/dante
.for cfg in sockd.conf socks-simple.conf socks.conf
	${INSTALL_DATA} ${WRKSRC}/example/${cfg} ${PREFIX}/share/examples/dante
.endfor

.include "../../mk/bsd.pkg.mk"
