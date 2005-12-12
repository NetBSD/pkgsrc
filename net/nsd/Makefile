# $NetBSD: Makefile,v 1.33 2005/12/12 20:34:14 joerg Exp $

DISTNAME=	nsd-2.3.3
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/nsd/index.html
COMMENT=	Authoritative-only DNS server

BUILD_DEFS+=	USE_INET6
BUILDLINK_DEPENDS.openssl+=	openssl>=0.9.7

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=--enable-bind8-stats
CONFIGURE_ARGS+=--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
.if !defined(USE_INET6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

CONFIGURE_ARGS+=--with-pidfile=${VARBASE}/run/nsd.pid
CONFIGURE_ARGS+=--with-user=nsd
CONFIGURE_ARGS+=--with-dbfile=${VARBASE}/db/nsd.db

RCD_SCRIPTS=	nsd
FILES_SUBST+=	NSDDB=${VARBASE}/db/nsd.db

USE_PKGINSTALL=		yes
PKG_GROUPS?=		nsd
PKG_USERS?=		nsd:nsd::nsd\ pseudo-user

.for _file_ in nsd.zones nsdc.conf
CONF_FILES+=		${EXAMPLEDIR}/${_file_} ${PKG_SYSCONFDIR}/nsd/${_file_}
.endfor

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
