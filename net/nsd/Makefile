# $NetBSD: Makefile,v 1.84 2016/03/15 13:48:35 pettai Exp $

DISTNAME=	nsd-4.1.9
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.nlnetlabs.nl/nsd/index.html
COMMENT=	Authoritative-only DNS server
LICENSE=	modified-bsd

BUILD_DEFS+=	VARBASE NSD_USER NSD_GROUP
FILES_SUBST+=   NSD_USER=${NSD_USER} NSD_GROUP=${NSD_GROUP}

BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7

PKG_OPTIONS_VAR=	PKG_OPTIONS.nsd
PKG_SUPPORTED_OPTIONS=	inet6 rrl
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes

PKG_SYSCONFSUBDIR=	nsd

CONFIGURE_ARGS+=--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=--localstatedir=${VARBASE}
CONFIGURE_ARGS+=--with-configdir=${PKG_SYSCONFDIR:Q}
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=--enable-ipv6
.else
CONFIGURE_ARGS+=--disable-ipv6
.endif
.if !empty(PKG_OPTIONS:Mrrl)
CONFIGURE_ARGS+=--enable-ratelimit
.else
CONFIGURE_ARGS+=--disable-ratelimit
.endif

CONFIGURE_ARGS+=--with-pidfile=${VARBASE}/run/nsd/nsd.pid
CONFIGURE_ARGS+=--with-user=${NSD_USER}
CONFIGURE_ARGS+=--with-dbfile=${VARBASE}/nsd/nsd.db
CONFIGURE_ARGS+=--with-xfrdfile=${VARBASE}/nsd/nsd-xfrd.state
CONFIGURE_ARGS+=--with-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=--with-ssl=${BUILDLINK_PREFIX.openssl}

RCD_SCRIPTS=	nsd

NSD_USER?=	nsd
NSD_GROUP?=	nsd

PKG_GROUPS=	${NSD_GROUP}
PKG_USERS=	${NSD_USER}:${NSD_GROUP}

CONF_FILES+=	share/examples/nsd/nsd.conf ${PKG_SYSCONFDIR}/nsd.conf

OWN_DIRS_PERMS+=        ${VARBASE}/nsd ${NSD_USER} ${NSD_GROUP} 755

INSTALLATION_DIRS=	share/examples/nsd
INSTALLATION_DIRS+=	${VARBASE}/nsd

CFLAGS.SunOS+=	-Du_int32_t=uint32_t

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
