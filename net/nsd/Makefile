# $NetBSD: Makefile,v 1.27 2005/01/19 02:11:24 itojun Exp $

DISTNAME=	nsd-2.2.0
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/nsd/index.html
COMMENT=	Authoritative-only DNS server

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes

CONFIGURE_ARGS=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=--enable-bind8-stats
CONFIGURE_ARGS+=--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
.if !defined(USE_INET6)
CONFIGURE_ARGS+=--disable-ipv6
.endif
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=--with-pidfile=${VARBASE}/run/nsd.pid
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

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
