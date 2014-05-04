# $NetBSD: Makefile,v 1.40 2014/05/04 17:04:48 wiz Exp $

DISTNAME=	memcached-1.4.19
CATEGORIES=	devel
MASTER_SITES=	http://www.memcached.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.memcached.org/
COMMENT=	High-performance distributed memory object caching system
LICENSE=	2-clause-bsd

USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}

REPLACE_PERL=		scripts/memcached-tool
RCD_SCRIPTS=		memcached
INSTALLATION_DIRS=	share/doc/${PKGBASE} share/examples/rc.d

.include "../../mk/bsd.prefs.mk"

.include "options.mk"

BUILD_DEFS+=		VARBASE
MEMCACHED_USER?=	memcached
MEMCACHED_GROUP?=	memcached
PKG_HOME?=		${VARBASE}/chroot/${PKGBASE}
PKG_GROUPS=		${MEMCACHED_GROUP}
PKG_USERS=		${MEMCACHED_USER}:${MEMCACHED_GROUP}::Memcached:${PKG_HOME}
PKG_GROUPS_VARS+=	MEMCACHED_GROUP
PKG_USERS_VARS+=	MEMCACHED_USER
OWN_DIRS_PERMS+=	${PKG_HOME} ${MEMCACHED_USER} ${MEMCACHED_GROUP} 0700
FILES_SUBST+=		MEMCACHED_USER=${MEMCACHED_USER}
FILES_SUBST+=		MEMCACHED_GROUP=${MEMCACHED_GROUP} PKG_HOME=${PKG_HOME}
MESSAGE_SUBST+=		PKG_HOME=${PKG_HOME}

TEST_TARGET=		test

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/memcached-tool ${DESTDIR}${PREFIX}/bin

.include "../../devel/libevent/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.0
.include "../../mk/bsd.pkg.mk"
