# $NetBSD: Makefile,v 1.4.2.1 2009/10/19 21:16:56 tron Exp $

DISTNAME=	unbound-1.3.4
CATEGORIES=	net
MASTER_SITES=	http://www.unbound.net/downloads/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.unbound.net/
COMMENT=	DNS resolver and recursive server

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--with-ldns=${BUILDLINK_PREFIX.ldns}
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run/unbound.pid

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-configure
SUBST_MESSAGE.paths=	Fixing path names
SUBST_FILES.paths=	doc/example.conf doc/*.5 doc/*.8
SUBST_SED.paths=	-e "s|/usr/local|${PREFIX}|"

INSTALL_MAKE_FLAGS+=	\
    configfile=${PREFIX}/share/examples/unbound/unbound.conf

PKG_SYSCONFSUBDIR=	unbound

CONF_FILES+=	share/examples/unbound/unbound.conf \
	${PKG_SYSCONFDIR}/unbound.conf

RCD_SCRIPTS=	unbound

UNBOUND_USER?=	unbound
UNBOUND_GROUP?=	unbound

PKG_GROUPS=	${UNBOUND_GROUP}
PKG_USERS=	${UNBOUND_USER}:${UNBOUND_GROUP}

.include "../../net/ldns/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
