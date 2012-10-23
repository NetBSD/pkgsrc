# $NetBSD: Makefile,v 1.23 2012/10/23 17:18:15 asau Exp $

DISTNAME=	dante-1.1.19
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.inet.no/pub/socks/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.inet.no/dante/
COMMENT=	BSD-licensed socks 4/5 proxy suite

CONFLICTS=	socks4-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-socks-conf=${PKG_SYSCONFDIR}/socks.conf
CONFIGURE_ARGS+=	--with-sockd-conf=${PKG_SYSCONFDIR}/sockd.conf

CHECK_PORTABILITY_SKIP=	contrib/StartupItems.Dante

RCD_SCRIPTS=		sockd

INSTALLATION_DIRS+=	share/examples/dante

post-install:
.for cfg in sockd.conf socks-simple.conf socks.conf
	${INSTALL_DATA} ${WRKSRC}/example/${cfg} ${DESTDIR}${PREFIX}/share/examples/dante
.endfor

.include "../../mk/bsd.pkg.mk"
