# $NetBSD: Makefile,v 1.22 2004/04/23 18:42:05 itojun Exp $

DISTNAME=	nsd-2.0.2
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/nsd/index.html
COMMENT=	Authoritative-only DNS server

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes

CONFIGURE_ARGS=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=--enable-bind8-stats
CONFIGURE_ARGS+=--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
.if !defined(USE_INET6)
CONFIGURE_ARGS+=--disable-ipv6
.endif
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=--with-pidfile=/var/run/nsd.pid
CONFIGURE_ARGS+=--with-user=named
CONFIGURE_ARGS+=--with-namedxfer=/usr/libexec/named-xfer
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/nsd
	${INSTALL_DATA_DIR} ${PREFIX}/share/nsd/contrib
.for FILE in README RELNOTES DIFFERENCES LICENSE NSD-DATABASE TODO
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/nsd
.endfor
.for FILE in README build-nsdzones.pl build-nsdzones.pl.README example-plugin.c
	${INSTALL_DATA} ${WRKSRC}/contrib/${FILE} ${PREFIX}/share/nsd/contrib
.endfor

.include "../../security/tcp_wrappers/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
