# $NetBSD: Makefile,v 1.29 2005/04/28 15:30:17 wiz Exp $

DISTNAME=	nsd-2.2.0
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/nsd/index.html
COMMENT=	Authoritative-only DNS server

BUILD_DEFS+=	USE_INET6
BUILDLINK_DEPENDS.openssl+=	openssl>=0.9.7

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=--enable-bind8-stats
CONFIGURE_ARGS+=--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
.if !defined(USE_INET6)
CONFIGURE_ARGS+=--disable-ipv6
.endif
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=--with-pidfile=${VARBASE}/run/nsd.pid
CONFIGURE_ARGS+=--with-user=named
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
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
