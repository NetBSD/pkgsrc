# $NetBSD: Makefile,v 1.43 2008/04/24 09:38:30 joerg Exp $

DISTNAME=	nsd-3.0.7
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/nsd/index.html
COMMENT=	Authoritative-only DNS server

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

PKG_OPTIONS_VAR=	PKG_OPTIONS.nsd
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

GNU_CONFIGURE=	yes

PKG_SYSCONFSUBDIR=	nsd

CONFIGURE_ARGS+=--with-configdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=--enable-bind8-stats
CONFIGURE_ARGS+=--with-libwrap=${BUILDLINK_PREFIX.tcp_wrappers}
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif

CONFIGURE_ARGS+=--with-pidfile=${VARBASE}/run/nsd.pid
CONFIGURE_ARGS+=--with-user=${NSD_USER}
CONFIGURE_ARGS+=--with-dbfile=${VARBASE}/db/nsd.db
CONFIGURE_ARGS+=--with-difffile=${VARBASE}/db/nsd-ixfr.db
CONFIGURE_ARGS+=--with-xfrdfile=${VARBASE}/db/nsd-xfrd.state
CONFIGURE_ARGS+=--with-ssl=${BUILDLINK_PREFIX.openssl}

RCD_SCRIPTS=	nsd

NSD_USER?=	nsd
NSD_GROUP?=	nsd

PKG_GROUPS=	${NSD_GROUP}
PKG_USERS=	${NSD_USER}:${NSD_GROUP}

CONF_FILES+=	share/examples/nsd/nsd.conf ${PKG_SYSCONFDIR}/nsd.conf

INSTALLATION_DIRS=	share/examples/nsd

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/nsd.zones2nsd.conf ${DESTDIR}${PREFIX}/share/examples/nsd

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
