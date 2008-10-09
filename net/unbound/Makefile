# $NetBSD: Makefile,v 1.2 2008/10/09 01:31:35 joerg Exp $

DISTNAME=	unbound-1.0.2
CATEGORIES=	net
MASTER_SITES=	http://www.unbound.net/downloads/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.unbound.net/
COMMENT=	DNS resolver and recursive server

PKG_DESTDIR_SUPPORT=	user-destdir

# Strictly speaking this is tar in gzip in gzip, but using bsdtar is
# the easiest workaround.
EXTRACT_USING=	bsdtar

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

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

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
