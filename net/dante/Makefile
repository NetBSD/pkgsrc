# $NetBSD: Makefile,v 1.29 2021/06/01 07:42:08 adam Exp $

DISTNAME=	dante-1.4.3
CATEGORIES=	net security
MASTER_SITES=	http://www.inet.no/dante/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.inet.no/dante/
COMMENT=	BSD-licensed socks 4/5 proxy suite
LICENSE=	modified-bsd

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
