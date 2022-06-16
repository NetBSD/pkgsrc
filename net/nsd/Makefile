# $NetBSD: Makefile,v 1.119 2022/06/16 16:23:01 ryoon Exp $

DISTNAME=	nsd-4.5.0
CATEGORIES=	net
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/nsd/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.nlnetlabs.nl/projects/nsd/about/
COMMENT=	Authoritative-only DNS server
LICENSE=	modified-bsd

BUILD_DEFS+=	VARBASE NSD_USER NSD_GROUP
FILES_SUBST+=	NSD_USER=${NSD_USER} NSD_GROUP=${NSD_GROUP}

PKG_OPTIONS_VAR=	PKG_OPTIONS.nsd
PKG_SUPPORTED_OPTIONS=	inet6 rrl
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.if ${OPSYS} == "NetBSD"
# Some _NETBSD_SOURCE definitions are required to build.
CPPFLAGS+=	-D_NETBSD_SOURCE
.endif

GNU_CONFIGURE=	yes

PKG_SYSCONFSUBDIR=	nsd

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-configdir=${PKG_SYSCONFDIR:Q}
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
.if !empty(PKG_OPTIONS:Mrrl)
CONFIGURE_ARGS+=	--enable-ratelimit
.else
CONFIGURE_ARGS+=	--disable-ratelimit
.endif

CONFIGURE_ARGS+=	--disable-dnstap

CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/nsd/nsd.pid
CONFIGURE_ARGS+=	--with-user=${NSD_USER}
CONFIGURE_ARGS+=	--with-dbfile=${VARBASE}/nsd/nsd.db
CONFIGURE_ARGS+=	--with-xfrdfile=${VARBASE}/nsd/nsd-xfrd.state
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

RCD_SCRIPTS=	nlnsd

NSD_USER?=	nsd
NSD_GROUP?=	nsd

PKG_GROUPS=	${NSD_GROUP}
PKG_USERS=	${NSD_USER}:${NSD_GROUP}

CONF_FILES+=	share/examples/nsd/nsd.conf ${PKG_SYSCONFDIR}/nsd.conf

OWN_DIRS_PERMS+=	${VARBASE}/nsd ${NSD_USER} ${NSD_GROUP} 755

INSTALLATION_DIRS=	share/examples/nsd

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
